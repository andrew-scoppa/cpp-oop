/*
The primary difference between const and constexpr is that constexpr 
is that the initialization of a const can be deferred until runtime. 

A constexpr must be initialized at compile time.

A constexpr function is one whose return value is computable at compile time. Consuming
code requires the return value be known at compile time to initialize a constexpr.
*/

#include <iostream>

using namespace std;


constexpr long exp(int x, int n)
{
    return n == 0 ? 1 :
                n % 2 == 0 ? exp(x * x, n / 2) :
                exp(x * x, (n - 1) / 2) * x;
}

int main()
{
    const int i = 2, j = 3;
    constexpr long k = exp(i, j);
    cout << k << endl;
}