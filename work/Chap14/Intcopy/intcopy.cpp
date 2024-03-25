//  intcopy.cpp
//
//  Copy a file of integers to a second file.
//
//  You may use the file primes.dat in this directory
//  as a sample input file of integers

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    char    inFile[80], outFile[80];
    cout << "input file: ";
    cin >> inFile;
    ifstream in(inFile);
    if (!in)
    {
        cout << "Can't open " << inFile << endl;
        exit(-1);
    }
    cout << "output file: ";
    cin >> outFile;
    ofstream out(outFile);
    if (!out)
    {
        cout << "Can't open " << outFile << endl;
        exit(-1);
    }
    int     num;
    while (in >> num)
        out << num << endl;

	return 0;
}
