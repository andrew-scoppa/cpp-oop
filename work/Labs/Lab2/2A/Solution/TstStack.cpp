//  TstStack.cpp
//
//  Interactive test program for IntStack class, version 2

#include <iostream>
#include <cstring>
#include "IntStack.h"

using namespace std;

int main()
{
	IntStack s;    
	int item;
	char cmd[80];				// command

	s.InitStack();
	cout << ": ";               // prompt
	cin >> cmd;
	while (strcmp(cmd, "quit") != 0)
	{
		if (strcmp(cmd, "push") == 0)
		{
			cout << "push item: ";
			cin >> item;
			s.Push(item);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			item = s.Pop();
			cout << "popped item = " << item << '\n';
		}
		else if (strcmp(cmd, "print") == 0)
			s.Print();
		else if (strcmp(cmd, "check") == 0)
		{
			// TO DO:	Add test code for invoking
			//			IsEmpty() and IsFull()
    		if (s.IsEmpty())
    			cout << "stack is empty\n" ;   
    		else
    			cout << "stack is not empty\n";   
    		if (s.IsFull())
    			cout << "stack is full\n";   
    		else
    			cout << "stack is not full\n";   
		}
		else
		{
			cout << "legal commands are:\n";
			cout << "\tpush\n"
				<< "\tpop\n"
				<< "\tprint\n"
				<< "\tcheck\n"
				<< "\tquit\n";
		}
		cout << ": ";
		cin >> cmd;
	}
	return 0;
}
