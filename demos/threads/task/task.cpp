// https://thispointer.com/c11-multithreading-part-10-packaged_task-example-and-tutorial/

#include <iostream> 
#include <future>   
#include <chrono>   
#include <thread>   
#include <functional>

void execute(std::function<int(int, int)> t, int from, int to)
{
    std::packaged_task<int(int, int)> task(t);

    auto future = task.get_future();

    std::thread worker_thread(std::move(task), from, to); // invoke the function

    std::cout << "task is running..." << std::endl;

    std::cout << "Elapsed time (s): " << future.get() << std::endl;

    worker_thread.join();
}
int main()
{
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
    // count down taking a second for each value:

    auto countdown = [](int from, int to) -> int
    {
        std::cout << "countdown thread id: " << std::this_thread::get_id() << std::endl;
        for (int i = from; i > to; --i)
        {
            std::cout << i << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "Lift off!\n";
        return from - to;
    };

    execute(countdown, 10, 0);

    return 0;
}