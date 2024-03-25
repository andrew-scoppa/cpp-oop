//  Strn.cpp
//
//  Implementation of String class, version 3

#pragma warning(disable : 4996)

#include <cstring>
#include "Trace.h"
#include "Strn.h"

String::String(const char *str)
{
	Trace("String::String(const char *str)");
	length = strlen(str);
	m_str = new char[length + 1];
	strcpy(m_str, str);
}

String::String(const String& other)
{
	Trace("String::String(const String& s)");
	length = other.length;
	m_str = new char[length + 1];
	strcpy(m_str, other.m_str);
}

String::~String()
{
	Trace("String::~String()");
	delete [] m_str;
}

void String::SetString(const char *str)
{
	delete [] m_str;
	length = strlen(str);
	m_str = new char[length + 1];
	strcpy(m_str, str);
}

const char * String::GetString()
{
	return m_str;
}
