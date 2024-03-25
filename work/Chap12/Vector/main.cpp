// main.cpp

// Uses vector<int> with "range for". 


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int total(vector<int> v);

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }

    cout << "Total: " << total(nums) << endl;

    return 0;
}

int total(vector<int> v)
{
    int sum = 0;
    for (const auto &n : v)
    {
        sum += n;
    }

    return sum;
}