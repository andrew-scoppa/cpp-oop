//  strn.h
//
//  Specification of String class

#ifndef _STRN_H
#define _STRN_H

#include <iostream>
using namespace std;

class String
{
public:
   String(const char *str = "");
   String(const String& s);
   ~String();
   String operator=(const char *str);
   String& operator=(const String& s);
   explicit operator const char* () const;
   String operator+(const String& str);
   friend ostream& operator<<(ostream& os, const String& s)
   {
      os << s.m_str;
      return os;
   }
   friend istream& operator>>(istream& is, String& s)
   {
      const int BUFSIZE = 100;
      char    buf[BUFSIZE];
      is >> buf;
      delete [] s.m_str;
      int newlength = strlen(buf);
      char *newtext = new char[newlength + 1];
      strcpy(newtext, buf);
      s.m_str = newtext;
      s.m_length = newlength;
      return is;
   }
private:
   char *m_str;
   int m_length;
};

#endif

