//  stack.h
//
//  Specification of Stack class
//
//	Converted from integer to general template class

#ifndef _STACK_H
#define	_STACK_H

#include <stdlib.h>
#include "trace.h"

const int STACKSIZE = 5;

template<class T>
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

template<class T>
Stack<T>::Stack()        
{
    top = 0;                
}

template<class T>
void Stack<T>::Push(const T& x)
{
    if (IsFull())
    {
        cerr << "ERROR: Stack is full\n";
        exit(1);
    }
    stack[top++] = x;
}

template<class T>
const T& Stack<T>::Pop()
{
    if (IsEmpty())
    {
        cerr << "ERROR: Stack is empty\n";
        exit(1);
    }
    return stack[--top];
}

template<class T>
void Stack<T>::Print()
{
    for (int i=top-1; i>=0; --i)
        Trace(stack[i]);
}

template<class T>
int Stack<T>::IsEmpty()
{
	return (top == 0);
}

template<class T>
int Stack<T>::IsFull()
{
	return (top == STACKSIZE);
}

#endif

