//  echostr.cpp
//
//  Echo strings, getline and write, empty line for EOF

#include <iostream>
#include <string.h>
using namespace std;

const int LIMIT = 80;

int main()
{
    char    buf[LIMIT];

    cout << "Enter strings, empty line for EOF\n";
    cin.getline(buf, LIMIT);
    while (strlen(buf) != 0)
    {
        cout.write(buf, strlen(buf));
        cout.put('\n');
        cin.getline(buf, LIMIT);
    }
	return 0;
}

