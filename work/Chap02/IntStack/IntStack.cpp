// IntStack.cpp
//
// Implementation of Integer Stack class

#include <iostream>
#include "IntStack.h"

void IntStack::InitStack()
{
    // top is index for next element to be put into array
    _top = 0; 

    // It is good practice to zero the data if not intialized to 0.
    for (int i = 0; i < STACKSIZE; ++i) {    
        _stack[i] = 0;						
    }

}

void IntStack::Push(int x)
{
    _stack[_top++] = x;
}

int IntStack::Pop()
{
    return _stack[--_top];
}

void IntStack::Print()
{
    for (int i=_top-1; i>=0; --i)
        std::cout << _stack[i] << '\n';
}