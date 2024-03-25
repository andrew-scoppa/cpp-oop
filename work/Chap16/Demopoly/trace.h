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

inline void Trace(char highLight, const char* str1, 
				  const char* str2, int num)
{
	cout << highLight << str1 << str2 << num << endl;
}

#endif
