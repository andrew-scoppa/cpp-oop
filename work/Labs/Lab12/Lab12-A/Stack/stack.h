//  stack.h
//
//  Specification of Stack class
//
//	TO DO:
//		Convert from integer to general template class

#ifndef _STACK_H
#define	_STACK_H

const int STACKSIZE = 5;

class IntStack              
{
public:
    IntStack();            
    void Push(int x);
    int Pop();
    void Print();
	int IsEmpty();
	int IsFull();
private:
    int stack[STACKSIZE];	// stack data
    int top;                // top of stack
};                          

#endif

