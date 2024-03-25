// Trace.h

#ifndef _TRACE_H
#define _TRACE_H

#include <iostream>
using namespace std;

inline void Trace(const char* str)
{
	cout << str << '\n';
}

inline void Trace(const char* str1, const char* str2)
{
	cout << str1 << str2 << '\n';
}

inline void Trace(const char* str1, int num)
{
	cout << str1 << num << '\n';
}

#endif
