//  TstStack.cpp
//
//  Interactive test program for IntStack class

#include <iostream>
#include <cstring>
#include "IntStack.h"

using namespace std;

int main()
{
    IntStack* ps = new IntStack();  
    int item;
    char cmd[80];        // command
    
    cout << ": ";        // prompt
    cin >> cmd;
    while (strcmp(cmd, "quit") != 0)
    {
		if (strcmp(cmd, "push") == 0)
		{
			if (ps != 0)
			{
				cout << "push item: ";
				cin >> item;
				ps->Push(item);
			}
		}
        else if (strcmp(cmd, "pop") == 0)
        {
			if (ps != 0)
			{
				item = ps->Pop();
				cout << "popped item = " << item << '\n';
			}
        }
        else if (strcmp(cmd, "print") == 0)
		{
			if (ps != 0)
			{
				ps->Print();
			}
		}
        else if (strcmp(cmd, "check") == 0)
		{
 			if (ps != 0)
			{
       			if (ps->IsEmpty())
        				cout << "stack is empty\n" ;   
    			else
    				cout << "stack is not empty\n";   
    			if (ps->IsFull())
    				cout << "stack is full\n";   
    			else
    				cout << "stack is not full\n";   
			}
		}
		else if (strcmp(cmd, "create") == 0)
		{
			cout << "size of new stack: ";
			long size;
			cin >> size;
			ps = new IntStack(size);
		}
		else if (strcmp(cmd, "destroy") == 0)
		{
			delete ps;
			ps = 0;
		}
       else
        {
            cout << "legal commands are:\n";
            cout << "\tpush\n"
                << "\tpop\n"
                << "\tprint\n"
                << "\tcheck\n"
                << "\tcreate\n"
                << "\tdestroy\n"
                << "\tquit\n";
        }
        cout << ": ";
        cin >> cmd;
    }
	return 0;
}
