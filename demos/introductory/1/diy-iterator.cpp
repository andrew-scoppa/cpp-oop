//  DemoStrn.cpp
//
//  Demo program for String class

#include <iostream>
using namespace std;

int main()
{
	int c[] = {1, 2, 3, 4, 5};

	const int count = sizeof(c) / sizeof(int);

	int *const begin = c;
	int *const end = c + count;

	for (int *it = begin; it < end; ++it)
	{
		cout << *it << endl;
	}

	int *it = begin;
	while (it < end)
	{
		cout << *it << endl;
		++it;
	}

	return 0;
}
