//  DemStack.cpp
//
//  Simple non-interactive demo program for IntStack class.

#include <iostream>
#include "IntStack.h"

int main()
{
    IntStack s;			// IntStack is a type

    int item;

    s.InitStack();		

    s.Push(10);
    s.Push(20);
    s.Push(30);
    
    s.Print();

    item = s.Pop();		// what is stored in item?
    std::cout << "Popped item = " << item << '\n';

    s.Print();

    return 0;
}