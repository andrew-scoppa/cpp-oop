// testadd.cpp

#include <iostream>
using namespace std;

extern "C" int add(int, int);

int main()
{
    cout << "5 + 7 = "  << add(5,7) << endl;
	return 0;
}
