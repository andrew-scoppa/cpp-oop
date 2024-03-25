#include <iostream>
#include <thread>
#include <chrono>

void FuncA()
{
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << (i + 1) << " Hello, world" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void FuncB()
{
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << (i + 1) << " Howdy, world" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }
}

int main()
{
    std::thread t1{FuncA}, t2{FuncB};

    std::cout << "Threads have be activated by main()" << std::endl;
    std::cout << "Waiting..." << std::endl;

    t1.join();
    t2.join();
    std::cout << "Done" << std::endl;
    return 0;
}
