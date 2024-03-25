#include <iostream>

using namespace std;

class Complex
{
private:
	int _r;
	int _i;

public:
	Complex(int real = 0, int imaginary = 1)
	{
		_r = real;
		_i = imaginary;
	}

	Complex(const Complex &rhs)
	{
		_r = rhs._r;
		_i = rhs._i;
	}

	operator double() const
	{
		return _r;
	}

	int getReal() const
	{
		return _r;
	}

	int getImaginary() const
	{
		return _i;
	}

	Complex operator*(Complex &rhs)
	{
		Complex prod;
		prod._r = this->_r * rhs._r - this->_i * rhs._i;
		prod._i = this->_r * rhs._i + this->_i * rhs._r;

		return prod;
	}

	/*
	TODO Implement overload for addition
	*/
};

int main()
{
	Complex c1(10, 0), c2(10,0);
	Complex prod = c1 * c2;

	cout << prod.getReal() << " + " << prod.getImaginary() << " i" << endl;

	cout << "double: " << prod << endl;
}
