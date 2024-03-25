#include <iostream>
#include <thread>
#include <chrono>

// define a lambda to replace FuncA
auto funcA = [](int lcv) -> void
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    for (size_t i = 0; i < lcv; i++)
    {
        std::cout << (i + 1) << " Hello, world" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
};

int main()
{
    std::thread t1{[](int lcv) -> void
                   {
                       std::this_thread::sleep_for(std::chrono::milliseconds(50));
                       for (size_t i = 0; i < lcv; i++)
                       {
                           std::cout << (i + 1) << " Hello, world" << std::endl;
                           std::this_thread::sleep_for(std::chrono::milliseconds(500));
                       }
                   },
                   5};

    std::cout << "Threads have be activated by main()" << std::endl;
    std::cout << "Waiting..." << std::endl;

    t1.join();

    std::cout << "Done" << std::endl;
    return 0;
}
