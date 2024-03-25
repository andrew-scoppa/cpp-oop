// castdemo.cpp
#include <iostream>

int main()
{
	long a;
	long *pa;
	short b;

	b = static_cast<short>(a);
	a = reinterpret_cast<long long>(pa);

	const int i = 0;

	int *qi = const_cast<int *>(&i);
	*qi = 10;

	return 0;
}
