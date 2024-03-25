//  tststack.cpp
//
//  Interactive test program for template stack classes
//
//  Commands:
//		ipop, ipush, iprint -- for integer stack
//
//      Reimplemented using template class .

#include <iostream>
#include <string.h>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int>  is;    
    int         item;
    char        cmd[80];        // command
    
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
        else
        {
            cout << "legal commands are:\n";
            cout << "\tipush\n"
                << "\tipop\n"
                << "\tiprint\n"
                << "\tquit\n";
        }
        cout << ": ";
        cin >> cmd;
    }
	return 0;
}
