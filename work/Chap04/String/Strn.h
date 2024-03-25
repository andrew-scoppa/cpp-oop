// Strn.h
//
// String class, version 1

#ifndef _STRN_H
#define _STRN_H

const int STRINGSIZE = 80;

class String
{
public:
	String();
	String(const char *str); // conversion ctor
	~String();
	void SetString(const char *str);
	const char *GetString();
private:
	char m_str[STRINGSIZE];
	
};

#endif


