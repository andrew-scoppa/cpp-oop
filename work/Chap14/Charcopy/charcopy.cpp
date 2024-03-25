//	charcopy.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
	string  inFile = "chardata.in";
	string  outFile = "chardata.out";
	ifstream  in(inFile);

	if ( ! in )
		cerr << "error in opening input file\n";

	ofstream  out(outFile);
	if ( ! out )
		cerr << "error in opening output file\n";

	char  ch;
	while  (in.get(ch))
		out.put(ch);
	return 0;
}
