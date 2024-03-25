//  TstStack.cpp
//
//  Simple interactive test program for IntStack class.

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
