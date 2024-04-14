// Trace.h
// Version 2

#ifndef _TRACE_H
#define _TRACE_H

#include <iostream>

inline void Trace(const char* str)
{
    std::cout << str << std::endl;
}

inline void Trace(const char* str1, const char* str2)
{
    std::cout << str1 << str2 << std::endl;
}

inline void Trace(const char* str1, int num)
{
    std::cout << str1 << num << std::endl;
}

inline void Trace(int num)
{
    std::cout << num << std::endl;
}


#endif
