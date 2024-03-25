/*
 https://www.geeksforgeeks.org/lambda-expression-in-c/
*/

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// Function to print vector
void printVector(vector<int> v)
{
	// lambda expression to print vector
	for_each(v.begin(), v.end(), [](int i)
			 { std::cout << i << " "; });
	cout << endl;
}

using func = bool(*)(int);
int sum(vector<int> nums, func pred)
{
	int total = 0;
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		if (pred(*it) == true)
		{
			total += *it;
		}
	}
	return total;
}

//
int sum(vector<int> nums, std::function<bool(int)> func)
{
	int total = 0;
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		if (func(*it) == true)
		{
			total += *it;
		}
	}
	return total;
}

int main()
{

	vector<int> nums = {10, 9, 3, 4, 5, 6, 2, 8, 9, 1};

	printVector(nums);


	sort(nums.begin(), nums.end(), [](const int &a, const int &b) -> bool // -> bool not necessary
		 { return a > b; });

	printVector(nums);

	auto count = std::count_if(nums.begin(), nums.end(), [](int a)
    {
        return (a >= 5);
    });
    cout << "The number of elements greater than or equal to 5 is : "
         << count << endl;

	return 0;
}
