// prevent this file from being included more than once
#pragma once

#define STACKSIZE 5

class IntStack              
{
public:
    void InitStack();            
    void Push(int x);
    int Pop();
    void Print();
	// TO DO: Add prototypes for IsEmpty() and IsFull()
	int IsEmpty();
	int IsFull();
private:
    int stack[STACKSIZE];	// stack data
    int top;                // top of stack
};                          
