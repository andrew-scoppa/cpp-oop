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
		out << c._r << "+" << c._i << "i";
		return out;
	}
	friend istream &operator>>(istream &in, Complex &c)
	{
		char op;
		in >> c._r >> op >> c._i;

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
	cout << "Enter complex number [X + Yi]: ";
	Complex c;

	cin >> c;

	cout << c << endl;

	cout << "Finished" << endl;
}
