#include <iostream>

using namespace std;

enum class Font{
    fancy = 0,
    stylish = 2,
    boring = 3
};

enum Permissions : unsigned
{
    None = 0,
    Owner = 0x2,
    Group = 0x4,
    Public = 0x8
};

void DisplayWelcome(string Message, Font font)
{
    switch (font)
    {
    case Font::fancy :
        /* code for fancy*/
        break;
    case Font::boring :
        /* code for boring*/
        break;
    case Font::stylish :
        /* code stylish*/
        break;
    default:
        /* otherwise*/
        break;
    }
}

int main()
{
    DisplayWelcome("Hello World!", Font::fancy);
    unsigned userPerms = Owner | Group;

}