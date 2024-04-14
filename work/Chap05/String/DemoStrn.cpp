//  DemoStrn.cpp
//
//  Demo program for String class

#include <iostream>
#include "Strn.h"

void PrintStrings(String *pa, String *px)
{
    std::cout << "pa = " << pa->GetString() << std::endl;
    std::cout << "px = " << px->GetString() << std::endl;
}

int main()
{
    String a("Alpha");
    String x;
    PrintStrings(&a, &x);
    x.SetString(a.GetString());
    PrintStrings(&a, &x);
    return 0;
}
