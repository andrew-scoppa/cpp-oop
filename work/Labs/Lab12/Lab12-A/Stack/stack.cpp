//  stack.cpp
//
//  Implementation of stack class
//
//  TO DO:
//		Convert to template class

#include <stdlib.h>
#include "trace.h"
#include "stack.h"

IntStack::IntStack()        
{
    top = 0;                // top is index for next element
                            // to be put into array

    for (int i=0; i<STACKSIZE; ++i)     // It is good practice
        stack[i] = 0;                   // to initialize the data.
}

void IntStack::Push(int x)
{
    if (IsFull())
    {
        cerr << "ERROR: Stack is full\n";
        exit(1);
    }
    stack[top++] = x;
}

int IntStack::Pop()
{
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
        Trace(stack[i]);
}

int IntStack::IsEmpty()
{
	return (top == 0);
}

int IntStack::IsFull()
{
	return (top == STACKSIZE);
}
