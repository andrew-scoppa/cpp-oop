#include <future>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

int adder(int ibegin, int iend)
{
    cout << this_thread::get_id() << " running" << endl;
    int sum = 0;
    for (size_t i = ibegin; i <= iend; i++)
    {
        sum += i;
        if (i % 10 == 0)
        {
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
    return sum;
}

int main()
{
    using namespace std::chrono;
    auto a = high_resolution_clock::now();
    vector<future<int>> v;
    v.push_back(std::async(launch::async, adder, 1, 1000));
    v.push_back(std::async(launch::async, adder, 1001, 2000));
    v.push_back(std::async(launch::async, adder, 2001, 3000));
    v.push_back(std::async(launch::async, adder, 3001, 4000));
    v.push_back(std::async(launch::async, adder, 4001, 5000));

    int sum = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        sum += v[i].get();
    }

    cout << sum << endl;

    auto b = high_resolution_clock::now();

    cout << endl
         << "Elapsed time: " << duration_cast<milliseconds>(b - a).count() << " milliseconds" << endl;
}
