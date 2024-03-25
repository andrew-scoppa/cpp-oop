#include <iostream>

using namespace std;

class RationalNumber
{
private:
	int m_Numerator;
	int m_Denominator;

public:
	RationalNumber(int num, int den) : m_Numerator(num), m_Denominator(den) {}
	int GetNumerator() const{
		return m_Numerator;
	}
	int GetDenominator() const{
		return m_Denominator;
	}
};

union Integer
{
	Integer() {} // important
	RationalNumber rational;
	int numerator;
	int denomintor;
};

int main()
{
	Integer number;
	number.numerator = 30;
	number.denomintor = 15;

	cout << number.rational.GetNumerator() << " / " << number.rational.GetDenominator() << endl;

	return 0;
}
