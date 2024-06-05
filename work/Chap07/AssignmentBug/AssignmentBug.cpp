//  AssignmentBug.cpp

#include <iostream>
#include "Strn.h"

int main()
{
    String a;
    String b("C++ rocks!");
    a = b ;
    std::cout << "a = " << a.GetString() << std::endl;
    std::cout << "b = " << b.GetString() << std::endl;
    return 0;
}
