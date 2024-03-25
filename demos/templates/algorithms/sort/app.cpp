#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;

template <typename PT, typename Comp>
void sort(PT begin, PT end, Comp comp)
{

	bool done;
	do
	{
		done = true;
		PT current = begin;
		while (current != (end - 1))
		{
			if (!comp(*current, *(current + 1)))
			{
				done = false;
				std::swap(*current, *(current + 1));
			}
			++current;
		}
	} while (!done);

	return;
}

int comp(int lhs, int rhs)
{
	return lhs < rhs;
}

int main()
{
	int values[] = {5, 4, 9, 2, 1, 6, 8, 7, 3};

	const size_t size = sizeof(values) / sizeof(int);
	int *pend = values + size;

	sort(values, pend, comp);

	for (size_t i = 0; i < size; i++)
	{
		cout << values[i] << endl;
	}

	return 0;
}
