// TestVector.cpp

#include <iostream>
#include "Vector.h"
using namespace std;

int Vector::size;

int main()
{
	// arrays must be of the same size
	int arr1[] = {1, 2, 3};
	int arr2[] = {1, 4, 9};

	Vector::size = sizeof(arr1) / sizeof(int);
	Vector v1;
	Vector v2;
	v1.Set(arr1);
	v2.Set(arr2);
	v1.Print();
	v2.Print();

	cout << "Product (friend) : "<< DotProduct(v1, v2) << endl;
	cout << "Product (operator *): "<< v1 * v2 << endl;
}


