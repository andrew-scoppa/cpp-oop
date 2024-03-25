#include <future>
#include <iostream>
#include <thread>
#include <string>

int main()
{
    auto promise = std::promise<std::string>();
    auto producer = std::thread([&] {
        // simulate some long-ish running task
        std::this_thread::sleep_for(std::chrono::seconds(5));
        promise.set_value("Message from producer...");
    });

    auto future = promise.get_future();
    auto consumer = std::thread([&] {
        std::cout << future.get() << std::endl;
    });

    producer.join();
    consumer.join();
}
