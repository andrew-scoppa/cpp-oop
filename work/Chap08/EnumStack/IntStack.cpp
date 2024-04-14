//  IntStack.cpp
//
//  Implementation of Integer Stack class  

#include <cstdlib>
#include <iostream>
#include "IntStack.h"
#include "Trace.h"

using std::cout, std::cerr, std::endl;

IntStack::IntStack()        
{
	Trace("IntStack::IntStack()");
	top = 0;                
	for (int i=0; i<STACKSIZE; ++i) 
		stack[i] = 0;                  
}

IntStack::~IntStack()
{
	Trace("IntStack::~IntStack()");
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
        cout << stack[i] << '\n';
}

int IntStack::IsEmpty()
{
	return (top == 0);
}

int IntStack::IsFull()
{
	return (top == STACKSIZE);
}
