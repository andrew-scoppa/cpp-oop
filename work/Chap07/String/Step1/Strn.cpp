//  Strn.cpp
//
//  Implementation of String class, version 4C

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

String::String(const String& s)
{
	Trace("String::String(const String& other)");
	length = s.length;
	m_str = new char[length + 1];
	strcpy(m_str, s.m_str);
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

const char* String::GetString() const
{
	return m_str;
}

String String::operator+(const String& s)
{
	char *buf = new char[length + s.length + 1];
	strcpy(buf, m_str);
	strcat(buf, s.m_str);
	String temp(buf);
	delete buf;
	return temp;
}

String& String::operator=(const String& other)
{
	Trace("operator=(const String& other)");
	if (this == &other)		// special case other = other
		return *this;
	this->length = other.length;
	delete [] this->m_str;
	this->m_str = new char[length + 1];
	strcpy(this->m_str, other.m_str);
	return *this;
}
