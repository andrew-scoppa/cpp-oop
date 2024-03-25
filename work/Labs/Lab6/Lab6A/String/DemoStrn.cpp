//  DemoStrn.cpp
//
//  Demo program for String class

#include <iostream>
#include "Strn.h"
using namespace std;

void PrintStrings(String a, String x)
{
	cout << "a = " << a.GetString() << endl;
	cout << "x = " << x.GetString() << endl;
}

int main()
{
	String a ("Alpha");
	String x;
	PrintStrings(a, x);
	x.SetString(a.GetString());
	PrintStrings(a, x);
	return 0;
}
