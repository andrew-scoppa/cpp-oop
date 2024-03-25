// Base.cpp

#include "Base.h"
#include "Trace.h"

Member::Member()
{
	Trace("Member::Member()");
	mm = 0;
}

Member::Member(int m)
{
	Trace("Member::Member(int m)");
	mm = m;
}

Member::~Member()
{
	Trace("Member::~Member()");
}

void Member::SetM(int m)
{
	mm = m;
}

void Member::Print()
{
	cout << "mm = " << mm << endl;
}

Base::Base()
{
	xx = 0;
	Trace("Base::Base()");
}

Base::Base(int x)
{
	Trace("Base::Base(int x)");
	xx = x;
}

Base::~Base()
{
	Trace("Base::~Base()");
}

void Base::SetX(int x)
{
	xx = x;
}

void Base::Print()
{
	cout << "xx = " << xx << endl;
}

Derived::Derived(int x, int y, int m) 
	: Base(x), mem(m)
{
	Trace("Derived::Derived(int y)");
	yy = y;
}

Derived::~Derived()
{
	Trace("Derived::~Derived()");
}

void Derived::Print()
{
	//Base::Print();
	cout << "xx = " << xx << endl;
	cout << "yy = " << yy << endl;
	mem.Print();
}