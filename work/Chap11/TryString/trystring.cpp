#include <string>
#include <iostream>
using std::string;
using std::cout, std::endl;

int main()
{
	string a = "Hello";
	string b = "world";
	string c = a + " " + b;
	cout << c << endl;
	cout << "length = " << c.length() << endl;
	return 0;
}
