//  Strn.h
//
//  Specification of String class, version 5

#ifndef _STRN_H
#define _STRN_H

class String
{
public:
	String(const char *str = "");
	String(const String& s);
	~String();
	void SetString(const char *str);
	String operator+(const String& str);
	String& operator=(const String& s);
	operator const char* () const;
	String operator=(const char *str);
private:
	char *m_str;
	int length;
};

#endif

