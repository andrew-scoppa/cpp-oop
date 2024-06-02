// prevent this file from being included more than once
#pragma once

#define STACKSIZE 100

class IntStack              // IntStack is tag-name
{
public:
	void InitStack();            
	void Push(int x);
	int Pop();
	void Print();

private:
	int stack[STACKSIZE]={0};	// stack data
	int top;                	// top of stack
};                          	// don't forget semicolon!!!


