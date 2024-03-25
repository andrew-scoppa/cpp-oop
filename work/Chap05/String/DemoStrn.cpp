//  DemoStrn.cpp
//
//  Demo program for String class

#include <iostream>
#include "Strn.h"
using namespace std;

// use pointer arguments to get around copy

void PrintStrings(String *pa, String *px)
{
	cout << "pa = " << pa->GetString() << endl;
	cout << "px = " << px->GetString() << endl;
}

int main()
{
	String a("Alpha");
	String x;
	PrintStrings(&a, &x);
	x.SetString(a.GetString());
	PrintStrings(&a, &x);
	return 0;
}
