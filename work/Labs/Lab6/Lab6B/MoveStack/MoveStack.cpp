// MoveStack.cpp
//
//	Step 2 -- use stack class with constructor

#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
	IntStack s1, s2;
	// Add data to first stack
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	// Show both stacks
	cout << "Stack 1:\n";
	s1.Print();
	cout << "Stack 2:\n";
	s2.Print();
	// Move contents to second stack
	while (!s1.IsEmpty())
	{
		int item = s1.Pop();
		s2.Push(item);
	}
	// Show both stacks
	cout << "Stack 1:\n";
	s1.Print();
	cout << "Stack 2:\n";
	s2.Print();
	return 0;
}

