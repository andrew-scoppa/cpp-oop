//  AssignmentBug.cpp

#include <iostream>
#include "Strn.h"
using namespace std;

int main()
{
	String a;
	String b("Alpha");
	a = b;
	cout << "a = " << a.GetString() << endl;
	cout << "b = " << b.GetString() << endl;
	return 0;
}
