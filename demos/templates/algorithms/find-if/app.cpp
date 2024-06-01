#include <iostream>
using std::cout;
using std::endl;

template<typename PT, typename Pred>
PT find_if(PT begin, PT end, Pred pred) {
	PT current = begin;
	while (current != end && !pred(*current)) {
		++current;
	}
	return current;
}

int comp(const int& lhs, const int &rhs){
	return lhs < rhs;
}

bool luckyNumber(int value)
{
	return value == 3;
}

int main()
{
	int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	const size_t size = sizeof(values) / sizeof(int);
	int *pend = values + size;

	int *pval = nullptr;
	
	cout << "find_if:" << endl;

	pval = find_if(values, pend, luckyNumber);

	if (pval == pend)
	{
		std::cout << "Lucky number not found" << std::endl;
	}
	else
	{
		std::cout << "Lucky number " << *pval << " found at address " << pval << std::endl;
	}
	return 0;
}

