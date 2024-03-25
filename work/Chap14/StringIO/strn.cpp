//  strn.cpp
//
//  Implementation of String class

#include <string.h>
#include "strn.h"

String::String(const char *str)
{
//	Trace("String::String(const char *str)");
    m_length = strlen(str);
    m_str = new char[m_length + 1];
    strcpy(m_str, str);
}

String::String(const String& s)
{
//	Trace("String::String(const String& s)");
    m_length = s.m_length;
    m_str = new char[m_length + 1];
    strcpy(m_str, s.m_str);
}

String::~String()
{
//	Trace("String::~String()");
    delete [] m_str;
}

String String::operator=(const char *str)
{
//	Trace("operator=(const char *str)");
    delete [] m_str;
    m_length = strlen(str);
    m_str = new char[m_length + 1];
    strcpy(m_str, str);
	return *this;
}

String& String::operator=(const String& s)
{
//	Trace("operator=(const String& s)");
	if (this == &s)		// special case s = s
		return *this;
	m_length = s.m_length;
    delete [] m_str;
    m_str = new char[m_length + 1];
    strcpy(m_str, s.m_str);
	return *this;
}

String::operator const char* () const
{
//	Trace("operator const char* () const");
    return m_str;
}

String String::operator+(const String& s)
{
	char *buf = new char[m_length + s.m_length + 1];
	strcpy(buf, m_str);
	strcat(buf, s.m_str);
	String temp(buf);
	delete buf;
	return temp;
}
