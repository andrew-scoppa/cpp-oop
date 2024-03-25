//  StringIO.cpp
//
//  Demo program for String class i/o

#include <iostream>
#include <fstream>
#include <string.h>
#include "strn.h"
using namespace std;

int main()
{
	String s1, s2, s3;
	cout << "String1: ";
	cin >> s1;
	cout << "String2: ";
	cin >> s2;
	s3 = s1 + s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;

	// now put output to a file "output.txt"
	ofstream out("output.txt");
	out << "s1 = " << s1 << endl;
	out << "s2 = " << s2 << endl;
	out << "s3 = " << s3 << endl;
	cout << "See also file output in \"output.txt\"" << endl;
	return 0;
}
