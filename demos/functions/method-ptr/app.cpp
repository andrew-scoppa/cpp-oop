#include "stdafx.h"
#include <iostream>
 
struct Greeter
{
    void welcome(std::string message)
    {
        std::cout << message << std::endl;
    }
 };


using pGreeter = void(Greeter::*)(std::string);

int main()
{
    
    Greeter g = Greeter{};

    pGreeter p = &Greeter::welcome;
    (g.*p)("Hello world!");
    
  
}