/*
https://en.cppreference.com/w/cpp/thread/condition_variable
https://cplusplus.com/reference/condition_variable/condition_variable/notify_one/
*/
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <csignal>
#include <atomic>
#include <vector>

using namespace std;

volatile atomic_bool cancel = false; // ctrl-c
volatile atomic_ulong Data = 0;
std::condition_variable cvDataChange;
std::condition_variable cvKeyboardInterupt;
std::mutex Mutex;

void interrupt_handler(int signal_num)
{
    cancel = true;
}

void Pump()
{
    while (!cancel)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        ++Data;
        cvDataChange.notify_all();
    }
}

void Logger()
{
    while (!cancel)
    {
        std::unique_lock<std::mutex> mlock(Mutex);
        cvDataChange.wait(mlock);

        cout << "Logger received data: " << Data << endl;
    }
}

int main()
{
    signal(SIGINT, interrupt_handler);

    thread pub(Pump); // start message pump

    vector<thread> v; // start listeners
    v.push_back(thread(Logger));
    v.push_back(thread(Logger));

    pub.join();

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i].join();
    }

    return 0;
}