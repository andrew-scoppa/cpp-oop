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
	cout << "size of stack is "
		 << IntStack::STACKSIZE << endl;

	s.Push(5);
	s.Push(7);
	s.Push(150);

	s.Print();

	item = s.Pop();		// what is stored in item?
	cout << "Popped item = " << item << '\n';

	s.Print();
	return 0;
}
