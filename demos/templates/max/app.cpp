#include "stdafx.h"
#include "trace.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <typename T> 
inline T Max(T a, T b)
{
	return (a > b) ? a : b;
}

const char* Max(const char *a, const char *b)
{
	if (strcmp(a, b) > 0)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void CompareInt()
{
	int x = 10, y = 20, z;

	z = Max(x, y);
	cout << z << endl;
}

void CompareStr()
{
	const char *a = "book";
	const char *b = "shelf";
	const char *c = Max(a, b);

	cout << c << endl;
}


//typedef  long (*func)(long, long);
using func=long (*)(long, long);
void CompareFunc(func f, long a, long b){
	cout << f(a, b) << endl;
}


int main()
{
	// Call one of the Compare functions
	long a = 10, b = 20;
	CompareFunc(Max, a, b);

	return 0;
}
