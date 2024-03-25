#include <iostream>
using namespace std;
void foo() noexcept(true) // see the noexcept specifier
{
    try
    {
        if (true)
            throw 42;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
int main()
{
    try
    {
        foo();
    }
    catch (...)
    {
        cerr << "exception caught\n";
    }
    return 0;
}