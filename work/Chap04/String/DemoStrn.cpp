//  DemoStrn.cpp
//
//  Demo program for String class

#include <iostream>
#include "Strn.h"

void PrintStrings(String source, String dest)
{
    std::cout << "source = " << source.GetString() << std::endl;
    std::cout << "dest = " << dest.GetString() << std::endl;
}

int main()
{
    String source = "Alpha";
    String dest;
    PrintStrings(source, dest);
    dest.SetString(source.GetString());
    PrintStrings(source, dest);
    return 0;
}
