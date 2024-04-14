// Strn.h
//
// String class, version 1

#ifndef _STRN_H
#define _STRN_H

/*
 * The String class provides functionality to work with strings of characters.
 * It includes methods to set and get the string value.
 */
class String
{
public:
	// Default constructor initializes the string to an empty string
	String();

	// Conversion constructor initializes the string to the specified C-style string
	String(const char *str);

	// Destructor
	~String();

	// Methods to set and get the string value
	void SetString(const char *str);
	const char *GetString();

private:
	static const int STRINGSIZE = 100; // Maximum size of the string
	char m_str[STRINGSIZE]; // The actual string data
};

#endif


