// Demonstrates use of new, delete, and nullptr

#include <iostream>
#include <cassert>

using namespace std;

int *Init(int n);

int main()
{
    int *p, n;

    cout << "Enter a count: ";
    cin >> n;

    p = Init(n);

    assert(p != nullptr);

    // use p then delete
    for (size_t i = 0; i < n; i++)
    {
        cout << *(p + i) << endl;
    }

    delete[] p;

    p = nullptr;
}

int *Init(int n)
{
    int *p;
    p = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        *(p + i) = 0;
    }

    return p;
}