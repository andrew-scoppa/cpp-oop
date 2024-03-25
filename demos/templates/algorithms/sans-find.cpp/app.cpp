#include <iostream>
using std::cout;
using std::endl;


// Following is a general approach (non-template) to locating a number in an array of ints:
int* find(int *begin, int *end, int value) {
	int *pCurrent = begin;
	while (pCurrent != end && *pCurrent != value) {
		++pCurrent;
	}
	std::cout << "non template" << std::endl;
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

