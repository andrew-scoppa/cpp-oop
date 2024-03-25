// tstarray.cpp

#include <string.h>
#include <iostream>
#include "trace.h"
#include "array.h"
using namespace std;

int main()
{
    Array<int>  array(5);   
    int			item;
	int			index;
    char        cmd[80];        // command
    
    cout << ": ";               // prompt
    cin >> cmd;
    while (strcmp(cmd, "quit") != 0)
    {
	    try
	    {
            if (strcmp(cmd, "set") == 0)
            {
 			    cout << "index: ";
			    cin >> index;
                cout << "set item: ";
                cin >> item;
			    array.SetAt(index, item);
            }
		    else if (strcmp(cmd, "get") == 0)
            {
			    cout << "index: ";
			    cin >> index;
                item = array.GetAt(index);
                cout << "get item = " << item << '\n';
            }
            else if (strcmp(cmd, "print") == 0)
                array.Print();
            else
            {
                cout << "legal commands are:\n";
                cout << "\tset\n"
                    << "\tget\n"
                    << "\tprint\n"
                    << "\tquit\n";
            }
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
