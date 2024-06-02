// Trace.h

#pragma once

#include <iostream>

inline void Trace(const char* str)
{
	std::cout << str << std::endl
}

inline void Trace(const char* str1, const char* str2)
{
	std::cout << str1 << str2 << std::endl
}

inline void Trace(const char* str1, int num)
{
	std::cout << str1 << num << std::endl;
}


