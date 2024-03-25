#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T, typename U, typename V>
void strategy(T *start, T *end, U func, V filter)
{
	T *current;
	current = start;
	while (current != end)
	{
		if (filter(*current))
		{
			func(*(current));
		}
		++current;
	};
}

void square(int &n)
{
	n *= n;
}

void trace(int n)
{
	std::cout << n << std::endl;
}

bool whereOdd(int n){
	if (n %2 == 1){
		return true;
	}
	return false;
}

int main()
{
	int ar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *start = ar;
	int *end = (ar + (sizeof(ar) / sizeof(int)));
	strategy<int>(start, end, square, whereOdd);
	strategy<int>(start, end, trace, whereOdd);
	return 0;
}
