#include <iostream>
#include <thread>
#include <chrono>

/*
TODO: refactor the code to define the lambda function separately before it's used.
Name the lambda function "threadFunction" and pass the lambda function to the thread constructor.
*/


int main()
{
    std::thread t1{[](int lcv) -> void
                   {
                        // log a message to the console that the thread has started
                        std::cout << "Thread has started" << std::endl;
                       for (size_t i = 0; i < lcv; i++)
                       {

                           std::this_thread::sleep_for(std::chrono::milliseconds(500));
                       }
                        // log a message to the console that the thread has finished
                          std::cout << "Thread has finished" << std::endl;
                   },
                   5};


    // wait for the thread to finish
    t1.join();

    std::cout << "Done!" << std::endl;
    return 0;
}
