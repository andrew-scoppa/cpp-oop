/*
This example demonstrates potential overhead
without perfect forwarding.
*/

#include <iostream>

using namespace std;

class Foo
{
public:
    Foo() { cout << "Regular ctor" << endl; }
    Foo(const Foo &obj) { cout << "Regular copy ctor" << endl; }
    Foo(Foo &&obj) { cout << "Move ctor" << endl; }
};

template <typename T>
void Func(T b)
{
    std::cout << "Func called" << std::endl;
}

template <typename T>
void FuncWrapper(T &&b)
{
    std::cout << "Wrapper called" << std::endl;
    Func<T>(std::forward<T>(b)); // Forward as lvalue or as rvalue, depending on T
}

int main()
{
    Foo obj;
    cout << "FuncWrapper called with  lvalue: " << endl;
    FuncWrapper(obj);
    cout << endl;
    cout << "FuncWrapper called with  rvalue: " << endl;
    FuncWrapper(std::move(obj));
}
