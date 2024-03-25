/*
First – create a function
Initialize a thread object
Synchronize thread to prevent the thread from simply ending.

*/

#include <iostream>
#include <thread>

void FuncA()
{
    std::cout << "Hello, world" << std::endl;
}

int main()
{
    std::thread t1{FuncA};
    t1.join();
    return 0;
}