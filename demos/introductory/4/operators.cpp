#include <iostream>
#include <ostream>

using namespace std;

class Rational
{
private:
    int _num;
    int _den;

public:
    Rational(int numerator = 0, int denominator = 1) : _num(numerator), _den(denominator)
    {
        /*
        _num = numerator;
        _den = denominator;
        */
    }

    Rational operator*(const Rational &rhs)
    {
        Rational temp(_num * rhs._num, _den * rhs._den);
        return temp;
    }

    operator double() const
    {
        return double(_num) / double(_den);
    }

    Rational &operator=(const Rational &rhs)
    {
        if (this == &rhs)
            return *this;
        this->_den = rhs._den;
        this->_num = rhs._num;
        return *this;
    }

    bool operator==(const Rational &rhs)
    {
        return (_den == rhs._den && _num == rhs._num);
    }

    void display()
    {
        cout << _num << '/' << _den << endl;
    }

    friend ostream& operator<<(ostream& os, Rational r);
};

ostream& operator<<(ostream& os, Rational r){
    os << r._num << "/" << r._den;
    return os;
}

int main()
{
    Rational r1(10);

    std::cout << (double)r1 << std::endl;

    return 0;
}
