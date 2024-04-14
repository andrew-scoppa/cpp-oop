//  StringBug.cpp
//
// This program demonstrates a bug in the String class.

#include <iostream>
#include "Strn.h"

void PrintString(String a)
{
    std::cout << "In PrintString a = " << a.GetString() << std::endl;
}

/* 
Count the number of times the destructor is called
and compare it to the number of times the constructor is called.
They should be the same. 
If they are not, then the program has a bug. 
*/
int main()
{
    String a("C++ is fun!");
    std::cout << "In main a = " << a.GetString() << std::endl;
    PrintString(a);
    std::cout << "In main a = " << a.GetString() << std::endl;
    return 0;
}
