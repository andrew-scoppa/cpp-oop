//  Strn.h
//
//  Specification of String class, version 2

#ifndef _STRN_H
#define _STRN_H

class String
{
public:
	String(const char *str = "");
	~String();
	void SetString(const char *str);
	const char *GetString();
private:
	char *m_str;
	int length;
};

#endif

