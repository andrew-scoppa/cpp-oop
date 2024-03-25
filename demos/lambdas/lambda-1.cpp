#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


double sumSquares(double x, double y) {
	return x * x + y * y;
}

double difSquares(double x, double y) {
	return x * x - y * y;
}

void doit(double(*fn)(double, double)) {
    char buffer [50];
	for (int i = 1; i < 10; i++) {
        sprintf (buffer, "fn(%d, %d) = %4.2f",i, 2 * i, fn(i, 2 * i));
		cout << buffer << endl;
	}
}

int main()
{
	auto lam = [](double x, double y) {
		return x * x + y * y;
	};
	cout << "lam(1, 20) = " << ([](double x, double y) {
		return x * x + y * y;
	})(1, 20) << endl;

	double result = lam(12, 12);
	cout << "lam(12, 12) = " << result << endl;

	doit(lam);

	return 0;
}

