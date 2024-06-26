
#include <iostream>     
#include <limits>
#include <cstdarg>     /* va_list, va_start, va_arg, va_end */

template <typename T>
T FindMax(T n, ...)
{
	T i, val, largest;
	va_list vl;
	va_start(vl, n);
	largest = va_arg(vl, T);
	for (i = 1; i < n; i++)
	{
		val = va_arg(vl, T);
		largest = (largest > val) ? largest : val;
	}
	va_end(vl);
	return largest;
}

int main()
{
	int m;
	m = FindMax(INT_MIN, 702, 422, 631, 834, 892, 104, 772);
	std::cout << "The largest value is:" << m << std::endl;
	return 0;
}