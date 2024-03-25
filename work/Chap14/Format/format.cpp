// format.cpp

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	vector<string> names = {"zero","one","two","three","four","five","six","seven","eight","nine"};

	int power = 1;
	for (int i = 0; i < names.size(); ++i)
	{
		cout << setiosflags(ios::left) 
			<< setw(8) << names[i]
			<< resetiosflags(ios::left)
			<< setw(3) << dec << i
			<< setw(7) << dec << power
			<< setw(7) << hex << power << endl;
		power *= 2;
	}
	return 0;
}
