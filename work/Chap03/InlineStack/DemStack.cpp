//  DemStack.cpp
//
//  Simple non-interactive demo program for IntStack class.

#include <iostream>
#include "IntStack.h"

/**
 * main() creates an instance of the IntStack class, initializes the stack,
 * pushes some items onto the stack, and then prints the contents of the stack.
 * Finally, it returns 0 to indicate successful execution of the program.
 */
int main()
{
    IntStack s;			// IntStack is a type
    int item;

    s.InitStack();		// need to initialize stack!
    s.Push(5);
    s.Push(7);
    s.Push(150);

	s.Print();

    return 0;
}