// trace.h

#ifndef _TRACE_H
#define _TRACE_H

#include <iostream>
using namespace std;

inline void Trace(const char* str)
{
	cout << str << endl;
}

inline void Trace(const char* str1, const char* str2)
{
	cout << str1 << str2 << endl;
}

inline void Trace(const char* str1, int num)
{
	cout << str1 << num << endl;
}

inline void Trace(int num)
{
	cout << num << endl;
}

inline void Trace(const char* str1, const char* str2, int num)
{
	cout << str1 << str2 << num << endl;
}

inline void Trace(const char* str1, double num)
{
	cout << str1 << num << endl;
}

inline void Trace(const char* str1, int num1, const char* str2, int num2)
{
	cout << str1 << num1 << str2 << num2 << endl;
}

#endif
