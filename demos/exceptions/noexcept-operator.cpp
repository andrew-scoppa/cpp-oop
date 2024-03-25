// Example of noexcept(expression) to test if an expression might throw

#include <iostream>
using namespace std;

void foo() { throw 42; }

void bar() noexcept {}

int main()
{
    if (noexcept(foo()))
        cout << "foo doesn't throw\n";
    else
        cout << "foo might throw\n";

            
    if (noexcept(bar()))
        cout << "bar doesn't throw\n";
    else
        cout << "bar might throw\n";
}
