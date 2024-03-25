//  Strn.h
//
//  Specification of String class, Version 3

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
private:
	char *m_str;
	int length;
};

#endif

