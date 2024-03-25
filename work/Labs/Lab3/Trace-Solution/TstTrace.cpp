// TstTrace.cpp

#include "Trace.h"

int main()
{
	Trace("label only");
	Trace("label & string: ", "foo");
	Trace("label & number: ", 999);
	return 0;
}
