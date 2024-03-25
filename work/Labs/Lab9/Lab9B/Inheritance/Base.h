// Base.h

class Member
{
public:
	Member();
	Member(int m);
	~Member();
	void SetM(int m);
	void Print();
private:
	int mm;
};

class Base
{
public:
	Base();
	Base(int x);
	~Base();
	void SetX(int x);
	void Print();
private:
	int xx;
};

class Derived : public Base
{
public:
	Derived(int x, int y);
	~Derived();
	void Print();
private:
	int yy;
	Member mem;
};