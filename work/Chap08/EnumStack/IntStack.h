//  IntStack.h
//
//  Specification of Integer Stack class
//  Demonstrates enum

#ifndef _INTSTACK_H
#define	_INTSTACK_H

class IntStack              
{
public:
	enum {STACKSIZE = 5};
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

