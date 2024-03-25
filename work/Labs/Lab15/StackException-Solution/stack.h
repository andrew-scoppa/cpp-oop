//  stack.h
//
//  Specification of Stack class
//
//	Converted from integer to general template class
//  Use of int parameter in class definition
//	Throws exception on error

#ifndef _STACK_H
#define	_STACK_H

#include <stdlib.h>
#include "trace.h"

template<class T, int STACKSIZE = 5>
class Stack              
{
public:
    Stack();            
    void Push(const T& x);
    const T& Pop();
    void Print();
	int IsEmpty();
	int IsFull();
private:
    T stack[STACKSIZE];		// stack data
    int top;                // top of stack
};                          

template<class T, int STACKSIZE>
Stack<T, STACKSIZE>::Stack()        
{
    top = 0;                // top is index for next element
                            // to be put into array
}

template<class T, int STACKSIZE>
void Stack<T, STACKSIZE>::Push(const T& x)
{
    if (IsFull())
        throw "ERROR: Stack is full\n";
    stack[top++] = x;
}

template<class T, int STACKSIZE>
const T& Stack<T, STACKSIZE>::Pop()
{
    if (IsEmpty())
        throw "ERROR: Stack is empty\n";
    return stack[--top];
}

template<class T, int STACKSIZE>
void Stack<T, STACKSIZE>::Print()
{
    for (int i=top-1; i>=0; --i)
        Trace(stack[i]);
}

template<class T, int STACKSIZE>
int Stack<T, STACKSIZE>::IsEmpty()
{
	return (top == 0);
}

template<class T, int STACKSIZE>
int Stack<T, STACKSIZE>::IsFull()
{
	return (top == STACKSIZE);
}

#endif

