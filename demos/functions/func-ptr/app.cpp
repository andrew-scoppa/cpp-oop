#include <iostream>
#include <string>

using namespace std;


double sumSquares(double x, double y) {
	return x * x + y * y;
}

double difSquares(double x, double y) {
	return x * x - y * y;
}


int main()
{

	typedef double(*mathfunc)(double, double); // mathfunc is a pointer to a function that takes two doubles and returns a double
	mathfunc pfn;


	pfn = sumSquares;
	double z = pfn(2, 3);
	cout << z << endl;

	mathfunc ar[10] = { nullptr };
	ar[0] = sumSquares;
	ar[1] = difSquares;

	for (mathfunc *p = ar; *p != nullptr; p++) {
		cout << (*p)(10, 10) << endl;
	}

	return 0;
}

