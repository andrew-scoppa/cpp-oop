/*
https://en.cppreference.com/w/cpp/thread/condition_variable
https://cplusplus.com/reference/condition_variable/condition_variable/notify_one/
*/
#include <future>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <atomic>
#include <csignal>
#include <functional>
/*
The thread that intends to modify the shared variable must:

1) Acquire a std::mutex (typically via std::lock_guard)
2) Modify the shared variable while the lock is owned
3) Call notify_one or notify_all on the std::condition_variable (can be done after releasing the lock)
*/

using namespace std;

template <typename T>
class Queue
{
public:
    T pop()
    {
        std::unique_lock<std::mutex> mlock(_mutex);
        _condition.wait(mlock, [&]()
                        { return !_queue.empty(); });
        auto item = _queue.front();
        _queue.pop();
        return item;
    }

    void push(const T &item)
    {
        std::unique_lock<std::mutex> mlock(_mutex);
        _queue.push(item);
        mlock.unlock();

        _condition.notify_one();
    }

private:
    std::queue<T> _queue;
    std::mutex _mutex;
    std::condition_variable _condition;
};

volatile atomic_bool cancel = false; // ctrl-c
std::condition_variable cvKeyboardInterupt;
std::mutex mxWorkers;

void interrupt_handler(int signal_num)
{
    cvKeyboardInterupt.notify_one();
}

void Worker(string message, int n, long long rest)
{
    std::unique_lock<std::mutex> mlock(mxWorkers);
    cout << message << ": " << n << endl;
    mlock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(rest));
}

void Process(int data)
{
    vector<thread> v; // start listeners
    v.push_back(thread(Worker, "A", data, 500));
    v.push_back(thread(Worker, "B", data, 250));
    v.push_back(thread(Worker, "C", data, 100));

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i].join();
    }
}

int main()
{
    const int size = 50;
    Queue<int> queue;

    auto qpush = [&]()
    {
        for (int i = 1; i <= size; i++)
        {
            if (cancel)
            {
                break;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            queue.push(i);
        };
    };

    auto qpull = [&]()
    {
        for (int i = 1; i <= size; i++)
        {
            if (cancel)
            {
                break;
            }

            int n = queue.pop();
            Process(n);
        };
    };

    signal(SIGINT, interrupt_handler);

    thread onKeyboardInterupt([]()
                     {  
                        std::unique_lock<std::mutex> mlock(mxWorkers);
                        cvKeyboardInterupt.wait(mlock);
                        clog << "Pipeline cancelled " << endl;
                        cancel = true;
                        mlock.unlock(); });

    onKeyboardInterupt.detach();

    thread pub(qpush);
    thread sub(qpull);

    pub.join();
    sub.join();
}