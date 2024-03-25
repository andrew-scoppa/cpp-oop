// tstarray.cpp

#include <string.h>
#include <iostream>
#include "trace.h"
#include "array.h"
using namespace std;

void execute(const char* cmd);

Array<int>  xarray(5);   

int main()
{
    char        cmd[80];        // command
    
    cout << ": ";               // prompt
    cin >> cmd;
    while (strcmp(cmd, "quit") != 0)
    {
		try
		{
			execute(cmd);
		}
		catch (const char * errmsg)
		{
			cerr << errmsg << '\n';
		}
		cout << ": ";
		cin >> cmd;
	}
	return 0;
}

void execute(const char* cmd)
{
	int item;
	int index;

	if (strcmp(cmd, "set") == 0)
	{
		cout << "index: ";
		cin >> index;
		cout << "set item: ";
		cin >> item;
		xarray.SetAt(index, item);
	}
	else if (strcmp(cmd, "get") == 0)
	{
		cout << "index: ";
		cin >> index;
		item = xarray.GetAt(index);
		cout << "get item = " << item << '\n';
	}
	else if (strcmp(cmd, "print") == 0)
		xarray.Print();
	else
	{
		cout << "legal commands are:\n";
		cout << "\tset\n"
			 << "\tget\n"
			 << "\tprint\n"
			 << "\tquit\n";
	}
}
