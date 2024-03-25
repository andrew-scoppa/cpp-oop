#include <iostream>
using namespace std;

// To handle base case of below recursive Variadic function Template
void print()
{
}

// Variadic function Template
template <typename T, typename... Types>
void print(T first, Types... varN)
{
    cout << first << endl;

    print(varN...);
}
struct Widget
{
    std::string operator()()
    {
        return "Widget";
    }
};

// Driver code
int main()
{
    Widget w;
    print(1, 2.0, w(), "xyz");

    return 0;
}