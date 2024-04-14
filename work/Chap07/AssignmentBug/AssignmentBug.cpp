//  AssignmentBug.cpp

#include <iostream>
#include <string>

int main()
{
    std::string a;
    std::string b("C++ rocks!");
    a = b;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}
