//  Concat.cpp
//
//  Demo concatenation program for String class (starter)

#include <cstring>
#include "Trace.h"
#include "Strn.h"

void Print3Strings(const String& a, const String& b, 
				   const String& x)
{
	Trace("1st = ", a.GetString());
	Trace("2nd = ", b.GetString());
	Trace("3rd = " ,x.GetString());
}

int main()
{
	String a("Alpha");
	String b("Beta");
	Print3Strings(a, b, a.Concat(b));
	return 0;
}
