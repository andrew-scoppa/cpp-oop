#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


class Dataset
{
private:
    enum
    {
        SIZE = 10,
    };
    int _data[SIZE]{0};
    void _alter_data(int n)
    {
        mutex m;
        for (size_t i = 0; i < SIZE; i++)
        {
            m.lock();
            _data[i] += (n + i);
            m.unlock();
        }
    }

public:
    Dataset()
    {
    }
    void operator()(int n) /* worker */
    {
        _alter_data(n);
    }
    const int *get() const { return _data; }
    size_t size() const { return SIZE; }
};

int main()
{
    Dataset ds;
    thread t1(std::ref(ds), 15);  // spawn new thread that calls worker ds(15)
    thread t2(std::ref(ds), 25); // spawn new thread that calls worker ds(15)
    t1.join();
    t2.join();
    
    const int *data = ds.get();
    for (size_t i = 0; i < ds.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }

    return 0;
}
