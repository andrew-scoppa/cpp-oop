//  DemoStrn.cpp
//
//  Demo program for String class

#include <iostream>
#include "Strn.h"
using namespace std;

void PrintStrings(String source, String dest)
{
	cout << "sourse = " << source.GetString() << endl;
	cout << "dest = " << dest.GetString() << endl;
}

int main()
{
	String source = "Alpha";
	String dest;
	PrintStrings(source, dest);
	dest.SetString(source.GetString());
	PrintStrings(source, dest);
	return 0;
}
