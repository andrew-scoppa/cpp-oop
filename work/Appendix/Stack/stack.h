//  stack.hpp
//
//  General Stack class implemented by templates.  (Simplified -- there
//  is no error checking, for example.)

#include <iostream>

const int STACKSIZE = 5;

template <class T>
class Stack   
{
public:
    Stack();                // constructor
    void Push(T x);
    T Pop();
    void Print();
private:
    T st[STACKSIZE];        // stack data
    int sp;                 // stack pointer
};

template <class T>
Stack<T>::Stack()           // constructor
{
    sp = 0;                 // sp is index for next element
                            // to be put into array

    for (int i=0; i<STACKSIZE; ++i)     // It is good practice
        st[i] = 0;                      // to initialize the data.
}

template <class T>
void Stack<T>::Push(T x)
{
    st[sp++] = x;
}

template <class T>
T Stack<T>::Pop()
{
    return st[--sp];
}

template <class T>
void Stack<T>::Print()
{
    for (int i=sp-1; i>=0; --i)
        cout << st[i] << "\n";
}
