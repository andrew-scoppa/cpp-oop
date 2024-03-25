/*  CStack.h

    Header file for C style version of integer stack module.
*/

#define STACKSIZE 10

// define the public functions for the interface for our one and only instance
void init();
void push(int x);
int pop();
void print();
