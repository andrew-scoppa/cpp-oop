//  tststack.cpp
//
//  Interactive test program for template stack classes
//
//  Commands:
//		ipop, ipush, iprint -- for integer stack
//		spop, spush, sprint -- for string stack
//
//      Reimplemented using template class with
//		two stack objects: integer and String.

#include <iostream>
#include <string.h>
#include "stack.h"
#include "strn.h"
using namespace std;

int main()
{
    Stack<int>		is;  
	Stack<String>	ss;
    int				item;
    char			cmd[80];    // command
    
    cout << ": ";               // prompt
    cin >> cmd;
    while (strcmp(cmd, "quit") != 0)
    {
        if (strcmp(cmd, "ipush") == 0)
        {
            cout << "push item: ";
            cin >> item;
            is.Push(item);
        }
        else if (strcmp(cmd, "ipop") == 0)
        {
            item = is.Pop();
            cout << "popped item = " << item << '\n';
        }
        else if (strcmp(cmd, "iprint") == 0)
            is.Print();
        else if (strcmp(cmd, "spush") == 0)
        {
			char buf[80];
            cout << "push item: ";
            cin >> buf;
            ss.Push((String) buf);
        }
        else if (strcmp(cmd, "spop") == 0)
        {
            String str = ss.Pop();
            cout << "popped item = " << (const char*) str << '\n';
        }
        else if (strcmp(cmd, "sprint") == 0)
            ss.Print();
        else
        {
            cout << "legal commands are:\n";
            cout << "\tipush\n"
                << "\tipop\n"
                << "\tiprint\n"
				<< "\tspush\n"
                << "\tspop\n"
                << "\tsprint\n"
                << "\tquit\n";
        }
        cout << ": ";
        cin >> cmd;
    }
	return 0;
}
