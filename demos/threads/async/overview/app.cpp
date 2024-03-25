
#include <future>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
struct cube
{
    int operator()(int i)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        return i * i * i;
    }
};

int product(int i, int j)
{
    this_thread::sleep_for(chrono::seconds(1));
    return i * j;
}

int main()
{
    
   
    future<int> f = std::async(launch::async, cube(), 3);
    std::cout << "cube running.." << std::endl;
    std::cout << "cube result is " << f.get() << std::endl;


}
