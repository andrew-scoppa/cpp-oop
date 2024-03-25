//  StringAssignment.cpp
//
// Use Version 4C of String class

#include <iostream>
#include "Strn.h"
using namespace std;


int main()
{
	String a;
	String b("Alpha");
	a = b;

	cout << "a = " << a.GetString() << endl;
	return 0;
}
