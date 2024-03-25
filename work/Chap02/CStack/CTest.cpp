//  CTest.cpp
//
//  Interactive test program for C style stack module

#include <iostream>
#include <cstring>
#include "CStack.h"

using namespace std;

int main()
{
    int item;
    char cmd[80]; // command

    init();
    cout << ": "; // prompt
    cin >> cmd;
    while (strcmp(cmd, "quit") != 0)
    {
        if (strcmp(cmd, "push") == 0)
        {
            cout << "push item: ";
            // read an integer item and push onto stack
            cin >> item;
            push(item);
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            // pop an item from stack and print a line
            // displaying the popped item
            item = pop();
            cout << "popped item = " << item << '\n';
        }
        else if (strcmp(cmd, "print") == 0)
        {
            // print all the items on the stack
            print();
        }
        else
        {
            cout << "legal commands are:\n";
            cout << "\tpush\n"
                 << "\tpop\n"
                 << "\tprint\n"
                 << "\tquit\n";
        }
        cout << ": ";
        cin >> cmd;
    }
    return 0;
}
