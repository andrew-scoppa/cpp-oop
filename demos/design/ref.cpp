#include <iostream>

int i = 0;

int &get()
{
    return ::i;
}

int main()
{
    int x = 10;
    int *px = &x;

    int &rx = x;
    int *&rpx = px;

    int ar[5] = {1, 2, 3, 4, 5};
    int(&rar)[5] = ar;

    get() = 5;

    std::cout << get() << std::endl;

    return 0;
}