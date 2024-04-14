// Trace.h

#ifndef _TRACE_H
#define _TRACE_H

#include <iostream>

inline void Trace(const char* str)
{
    std::cout << str << '\n';
}

inline void Trace(const char* str1, const char* str2)
{
    std::cout << str1 << str2 << '\n';
}

inline void Trace(const char* str1, int num)
{
    std::cout << str1 << num << '\n';
}

#endif
