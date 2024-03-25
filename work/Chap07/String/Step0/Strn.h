//  Strn.h
//
//  Specification of String class, version 4A

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
	String Concat(const String& str);
private:
	char *m_str;
	int length;
};

#endif

