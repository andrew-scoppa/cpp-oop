#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Rational
{
private:
    int _num;
    int _den;
    // function to compute greatest common denominator
    int _gcd()
    {
        int result = min(_num, _den);
        while (result > 0)
        {
            if (_num % result == 0 && _den % result == 0)
            {
                break;
            }
            result--;
        }
        return result; // return gcd of _num and _den
    }

public:
    Rational(int numerator = 0, int denominator = 1) : _num(numerator), _den(denominator)
    {
    }

    int Numerator() const
    {
        return _num;
    }

    int Denominator() const
    {
        return _den;
    }

    Rational operator*(const Rational &rhs)
    {
        Rational temp(_num * rhs._num, _den * rhs._den);
        return temp;
    }

    void Reduce()
    {
        int gcd = _gcd();
        _num /= gcd;
        _den /= gcd;
    }

    explicit operator double() const
    {
        return double(_num) / double(_den);
    }

    bool operator==(const Rational &rhs) const
    {
        return (_den == rhs._den && _num == rhs._num);
    }

    bool operator!=(const Rational &rhs) const
    {
        return !(*this == rhs);
    }

    // add operator overloads for less and greater
    bool operator<(const Rational &rhs) const
    {
        return (double)(*this) < (double(rhs));
    }
    bool operator>(const Rational &rhs) const
    {
        return (double)(*this) > (double(rhs));
    }
    //

    Rational operator++(int) // postfix
    {
        Rational t = *this;
        _num = _num + _den;
        return t;
    }

    Rational &operator++() // prefix
    {
        _num = _num + _den;
        return *this;
    }

    string ToString() const
    {
        return std::to_string(_num) + "/" + std::to_string(_den);
    }

    friend ostream &operator<<(ostream &os, Rational r);
};

ostream &operator<<(ostream &os, Rational r)
{
    int whole = r._num / r._den;
    int remainder = r._num % r._den;
    if (whole == 0 && remainder == 0)
    {
        os << 0;
        return os;
    }

    if (whole != 0)
    {
        os << whole << " ";
    }
    if (remainder != 0)
    {
        os << remainder << "/" << r._den;
    }

    return os;
}

int main()
{
    Rational r1(26, 10);
    r1.Reduce();
    Rational r2 = r1 * 2;

    std::cout << r1 << std::endl;
    return 0;
}
