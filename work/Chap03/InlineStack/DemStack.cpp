//  DemStack.cpp
//
//  Simple non-interactive demo program for IntStack class.

#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
	IntStack s;			// IntStack is a type
	int item;

	s.InitStack();		// need to initialize stack!
	s.Push(5);
	s.Push(7);
	s.Push(150);

	s.Print();

	item = s.Pop();		
	cout << "Popped item = " << item << '\n';

	s.Print();

	//item = s.top;		// Not legal - Why not?

	return 0;
}
