/*  CStack.cpp

    Stack module.  This file is compiled as a separate module and
    linked to modules that use the stack.  C style implementation of an
    integer stack.  
*/

#include <iostream>
#include "CStack.h"

using namespace std;


/*
A variable defined outside any function and with the keyword static has file scope.
It can be accessed from any function in the file but not from outside the file.
*/
static int stack[STACKSIZE];    /* stack data */
static int top = 0;             /* top of stack */


void init()
{
	for (int i = 0; i < top; ++i)
		stack[i] = 0;
}

void push(int x)
{
	if (top > STACKSIZE) {
		return;
	}
    stack[top++] = x;
}

int pop()
{
	if (top == 0) {
		return 0;
	}
    return stack[--top];
}

void print()
{
    for (int i = top-1; i >= 0; --i)
        cout << stack[i] << '\n';
}


