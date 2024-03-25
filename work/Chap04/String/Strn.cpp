// Strn.cpp
//
// String class, version 1
#pragma warning(disable : 4996)

#include <cstring>
#include "Trace.h"
#include "Strn.h"

String::String()
{
	Trace("String::String()");
	strcpy(m_str, "");
}

String::String(const char *str) // conversion ctor
{
	Trace("String::String(const char *str)");
	strcpy(m_str, str);
}

String::~String()
{
	Trace("String::~String()");
}

void String::SetString(const char *str)
{
	strcpy(m_str, str);
}

const char * String::GetString()
{
	return m_str;
}


