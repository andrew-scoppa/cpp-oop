//  IntStack.h
//
//  Specification of Integer Stack class, version 3

#ifndef _INTSTACK_H
#define	_INTSTACK_H

const int STACKSIZE = 5;

class IntStack              
{
public:
	IntStack(); 
	~IntStack();
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

