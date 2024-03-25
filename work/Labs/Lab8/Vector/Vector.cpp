// Vector.cpp

#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector()
{
	m_vec = new int[size];
}

Vector::~Vector()
{
	delete [] m_vec;
}

void Vector::Set(int *arr)
{
	for (int i = 0; i < size; i++)
		m_vec[i] = arr[i];
}
		
void Vector::Print()
{
	for (int i = 0; i < size; i++)
		cout << m_vec[i] << "  ";
	cout << endl;
}

int Vector::DotProduct(const Vector& v)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += m_vec[i] * v.m_vec[i];
	return sum;
}
