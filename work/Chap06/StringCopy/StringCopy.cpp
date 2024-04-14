//  StringCopy.cpp

#pragma warning(disable : 4996)

#include <iostream>
#include "Strn.h"

void PrintString(String a)
{
	std::cout << "In PrintString a = " << a.GetString() << std::endl;
}

int main()
{
	String a("C++ is fun!");
	std::cout << "In main a = " << a.GetString() << std::endl;
	PrintString(a);
	std::cout << "In main a = " << a.GetString() << std::endl;
	return 0;
}
