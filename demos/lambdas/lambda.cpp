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

int main()
{

	vector<int> nums = {10, 9, 3, 4, 5, 6, 2, 8, 9, 1};

	printVector(nums);

    int n = sum(nums, [](int n){ return n % 2 == 0;});
    auto odd = [](int n){ return n % 2 == 1;};
    int m = sum(nums, odd);

    cout << n << "\t" << m << endl;

	return 0;
}
