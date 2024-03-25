
#include <future>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
struct cube
{
    int operator()(int i)
    {
        this_thread::sleep_for(chrono::milliseconds(1500));
        return i * i * i;
    }
};

int product(int i, int j, int k)
{
    this_thread::sleep_for(chrono::seconds(5));
    return i * j;
}

int main()
{
    
    future<int> g = std::async(
        launch::deferred,
        product,
        10, 100, 1000);
    std::cout << "product deferred..." << std::endl;

    future<int> f = std::async(launch::async, cube(), 3);
    std::cout << "cube running.." << std::endl;
    // do more work

    std::cout << "cube result is " << f.get() << std::endl;

    // more work

    std::cout << "product result is " << g.get() << std::endl;
}
