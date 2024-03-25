//  StringCopy.cpp
//
// Use Version 3 of String class

#pragma warning(disable : 4996)

#include <iostream>
#include "Strn.h"
using namespace std;

void PrintString(String a)
{
	cout << "a = " << a.GetString() << endl;
}

int main()
{
	String a("Alpha");
	cout << "a = " << a.GetString() << endl;
	PrintString(a);
	cout << "a = " << a.GetString() << endl;
	return 0;
}
