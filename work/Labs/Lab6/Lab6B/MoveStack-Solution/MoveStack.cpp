// MoveStack.cpp
//


#include <iostream>
#include "IntStack.h"
using namespace std;

void MoveStack(IntStack* ps1, IntStack* ps2)
{
	while (!ps1->IsEmpty())
	{
		int item = ps1->Pop();
		ps2->Push(item);
	}
}

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
	MoveStack(&s1, &s2);
	// Show both stacks
	cout << "Stack 1:\n";
	s1.Print();
	cout << "Stack 2:\n";
	s2.Print();
	return 0;
}

