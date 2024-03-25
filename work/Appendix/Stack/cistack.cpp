//  cistack.cpp
//
//  C callable interface to IntStack class.

#include "istack.h"

extern "C"
{
    void PushStack(int);
    int PopStack();
    void PrintStack();
}

IntStack    stack;

void PushStack(int x)
{
    stack.Push(x);
}

int PopStack()
{
    return stack.Pop();
}

void PrintStack()
{
    stack.Print();
}
