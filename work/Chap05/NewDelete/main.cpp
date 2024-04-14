// Demonstrates use of new, delete, and nullptr

#include <iostream>
#include <cassert>

int *Init(int n);

int main()
{
    int *p, n;

    std::cout << "Enter a count: ";
    std::cin >> n;

    // allocate storage for n integers
    p = Init(n);

    // check for nullptr
    assert(p != nullptr);

    // populate the storage with integers
    for (size_t i = 0; i < n; i++)
    {
        *(p + i) = i + 1;
    }

    // display the integers
    for (size_t i = 0; i < n; i++)
    {
        std::cout << *(p + i) << std::endl;
    }

    // deallocate the storage
    delete[] p;

    // set p to nullptr
    p = nullptr;
}

/*
The function 'Init' allocates storage for n integers and initializes them to 0.
It returns a pointer to the storage.
If n is 0, it returns nullptr.
*/
int *Init(int n)
{
    if (n == 0)
    {
        return nullptr;
    }

    int *p = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        *(p + i) = 0;
    }

    return p;
}