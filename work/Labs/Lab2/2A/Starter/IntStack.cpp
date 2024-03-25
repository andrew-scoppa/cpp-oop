// IntStack.cpp
//
// Implementation of Integer Stack class, version 1

#include <iostream>
#include "IntStack.h"

using namespace std;

void IntStack::InitStack()
{
	top = 0; // top is index for next element

	for (int i = 0; i < STACKSIZE; ++i)
		stack[i] = 0; // initialize the data.
}

void IntStack::Push(int x)
{
	stack[top++] = x;
}

int IntStack::Pop()
{
	return stack[--top];
}

void IntStack::Print()
{
	for (int i = top - 1; i >= 0; --i)
		cout << stack[i] << '\n';
}

// TO DO:  Implement IsEmpty() and IsFull()