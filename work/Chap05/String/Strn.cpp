//  Strn.cpp
//
//  Implementation of String class
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
