#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

class Complex
{
private:
	int _r;
	int _i;

public:
	Complex(int real = 0, int imaginary = 1)
		: _r(real), _i(imaginary)
	{
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

	friend ostream &operator<<(ostream &out, const Complex &c)
	{
		// implement the operation

		return out;
	}
	friend istream &operator>>(istream &in, Complex &c)
	{
		// implement the operation

		return in;
	}

	Complex operator*(const Complex &rhs)
	{
		Complex prod;
		prod._r = this->_r * rhs._r - this->_i * rhs._i;
		prod._i = this->_r * rhs._i + this->_i * rhs._r;

		return prod;
	}
};

int main()
{
	Complex c;
	cout << "Enter complex number [X + Yi]: ";

	// Using your implementation of the overloaded >> and << operations,
	// read in a complex value (e.g. 10 + 2i), then outpot the value

	cout << "Finished" << endl;
}
