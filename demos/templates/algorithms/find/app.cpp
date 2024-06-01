#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T *find(T *begin, T *end, T value)
{
	T *pCurrent = begin;
	while (pCurrent != end && *pCurrent != value)
	{
		++pCurrent;
	}
	return pCurrent;
}


int main()
{
	int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	const size_t size = sizeof(values) / sizeof(int);
	int *pend = values + size;

	const int num2find = 5;
	cout << "find:" << endl;

	int *pval = nullptr;
	
	pval = find(values, pend, num2find);

	if (pval == pend)
	{
		std::cout << num2find << " not found" << std::endl;
	}
	else
	{
		std::cout << num2find << " found at address " << pval << std::endl;
	}

	return 0;
}

