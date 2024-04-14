//  StringAssignment.cpp
//



#include <iostream>
#include "Strn.h"

int main()
{
    String a;
    String b("Alpha");
    a = b;

    std::cout << "a = " << a.GetString() << std::endl;
    return 0;
}