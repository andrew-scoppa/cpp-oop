// intstring.cpp

#include <string>
#include <iostream>
using namespace std;

int main()
{
	int alpha[] = {2, 3, 5, 34};
	int beta[] = {7, 11, 13};

	size_t l = sizeof(alpha) / sizeof(int);
	size_t m = sizeof(beta) / sizeof(int);

	cout << "l: " << l << endl;
	cout << "m: " << m << endl;

	basic_string<int> a(alpha, l);
	basic_string<int> b(beta, m);
	basic_string<int> c;
	c = a + b;
	cout << "length = " << c.length() << endl;
	for (int i = 0; i < c.length(); i++)
		cout << c[i] << endl;
	return 0;
}
