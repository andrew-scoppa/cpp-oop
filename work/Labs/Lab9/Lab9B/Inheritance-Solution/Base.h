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
protected:
	int xx;
};

class Derived : public Base
{
public:
	Derived(int x, int y, int m = 0);
	~Derived();
	void Print();
private:
	int yy;
	Member mem;
};