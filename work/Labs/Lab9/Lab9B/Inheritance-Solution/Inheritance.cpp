// Inheritance.cpp

#include "Base.h"

int main()
{
	Base a(5);
	Derived d(77, 33, 99);
	a.Print();
	d.Print();
	return 0;
}