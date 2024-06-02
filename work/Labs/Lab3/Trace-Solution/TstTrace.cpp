// TstTrace.cpp

#include "Trace.h"

int main()
{
	Trace("label only");
	Trace("label & string: ", "Hello World!");
	Trace("label & number: ", 999);
	return 0;
}
