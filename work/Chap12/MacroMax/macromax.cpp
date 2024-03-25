// macromax.cpp

#include "trace.h"

#define Max(a, b) (a > b) ? a : b

int main()
{
	int a = 7;
	int b = 50;
	Trace("Before");
	Trace("a = ", a);
	Trace("b = ", b);
	Trace("Max = ", Max(a++, b++));
									
	Trace("");
	Trace("After");
	Trace("a = ", a);
	Trace("b = ", b);
	return 0;
}
