#include <iostream>

int i = 0;

int &get()
{
    return ::i;
}

int main()
{
    int x = 10;                      // x is an int
    int *px = &x;                   // px is a pointer to an int

    int &rx = x;                    // rx is a reference to an int
    int *&rpx = px;                 // rpx is a reference to a pointer to an int

    int ar[5] = {1, 2, 3, 4, 5};    // ar is an array of 5 ints
    int(&rar)[5] = ar;              // rar is a reference to an array of 5 ints

    get() = 5;                      // i is now 5

    std::cout << get() << std::endl;

    return 0;
}