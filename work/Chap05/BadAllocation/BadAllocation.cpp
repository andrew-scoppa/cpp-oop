// BadAllocation.cpp

#include <iostream>
#include <new>
#include <climits>
using namespace std;

class Big
{
	long arr[1000000];
};

int main()
{
	long n = LONG_MAX;
	cout << "Size of one Big instance (bytes): " << sizeof(*(new Big())) << endl;
	cout << "Attempt to create " << n << " instances..." << endl;
	try
	{
		Big* huge = new Big[n];
		cout << "Succeeded" << endl;
	}
	catch (bad_alloc &ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}