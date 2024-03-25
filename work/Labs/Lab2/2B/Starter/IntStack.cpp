//  IntStack.cpp
//
//  Implementation of Integer Stack class.  

#include <iostream>
#include "IntStack.h"

using namespace std;

void IntStack::InitStack()        
{
    top = 0;                // top is index for next element
                            // to be put into array

    for (int i=0; i<STACKSIZE; ++i)     // It is good practice
        stack[i] = 0;                   // to initialize the data.
}

void IntStack::Push(int x)
{
	// TO DO:  Check for full condition
    if (IsFull())
    {
        cerr << "ERROR: Stack is full\n";
        exit(1);
    }
    stack[top++] = x;
}

int IntStack::Pop()
{
	// TO DO:  Check for empty condition
    if (IsEmpty())
    {
        cerr << "ERROR: Stack is empty\n";
        exit(1);
    }
    return stack[--top];
}

void IntStack::Print()
{
    for (int i=top-1; i>=0; --i)
        cout << stack[i] << '\n';
}

// TO DO:  Implement IsEmpty() and IsFull()

int IntStack::IsEmpty()
{
	return (top == 0);
}

int IntStack::IsFull()
{
	return (top == STACKSIZE);
}
