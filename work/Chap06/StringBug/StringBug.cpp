//  StringBug.cpp
//
// Use Version 2 of String class

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
