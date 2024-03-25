//  istack.cpp  
//
//  Implementation of Integer Stack class.  (Simplified -- there
//  is no error checking, for example.)

#include <iostream>
#include "istack.h"
using namespace std;

IntStack::IntStack()        // constructor
{
    sp = 0;                 // sp is index for next element
                            // to be put into array

    for (int i=0; i<STACKSIZE; ++i)     
        st[i] = 0;                      
}

void IntStack::Push(int x)
{
    st[sp++] = x;
}

int IntStack::Pop()
{
    return st[--sp];
}

void IntStack::Print()
{
    for (int i=sp-1; i>=0; --i)
        cout << st[i] << endl;
}
