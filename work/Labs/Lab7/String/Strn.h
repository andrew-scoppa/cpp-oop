//  Strn.h
//
//  Specification of String class, version 4D

#ifndef _STRN_H
#define _STRN_H

class String
{
public:
	String(const char *str = "");
	String(const String& s);
	~String();
	void SetString(const char *str);
	const char *GetString() const;
	String operator+(const String& str);
	String& operator=(const String& s);
	operator const char* () const;
private:
	char *m_str;
	int length;
};

#endif

