// Virtdemo.cpp

#include <iostream>
using namespace std;

class B
{
public:
	void f();
	void g();
private:
	long x;
};

class D : public B
{
public:
	void f();
	void g();
private:
	long y;
};

void B::f() {cout << "B::f" << endl;}
void B::g() {cout << "B::g" << endl;}
void D::f() {cout << "D::f" << endl;}
void D::g() {cout << "D::g" << endl;}

int main()
{
	B	b, *pb;
	D	d, *pd;
	pb = &b;
	pd = &d;
	b.f();
	d.f();
	pb->f();
	pd->f();
	// pb = pd;	// legal?? 
	pb->f();
	// pd = pb;	// legal??
	cout << "size B = " << sizeof(B) << endl;
	cout << "size D = " << sizeof(D) << endl;
	return 0;
}

