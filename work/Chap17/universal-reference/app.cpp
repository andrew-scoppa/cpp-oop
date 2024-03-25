#include <iostream>
using std::cout, std::endl;

template <typename T>
void func(T &&t)
{
    // "T &&" is a UNIVERSAL REFERENCE
    cout << t << endl;
}

void foo(int &i){
    cout << i << " lvalue ref" << endl;
}

void foo(int &&i){
    cout << i << " rvalue ref" << endl;
}

int main()
{
    int i = 42;
    foo(1);
    foo(i);
    func(i);  // lvalue, "T &&" deduced to be "int &"
    func(42); // rvalue, "T &&" deduced to be "int &&";
}
