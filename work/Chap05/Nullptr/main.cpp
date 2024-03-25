#include <iostream>
#include <cassert>

using namespace std;

void Swap(int *p1, int *p2)
{
    assert(p1 != nullptr && p2 != nullptr);
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a = 5, b = 10;
    int *pa = &a, *pb = nullptr;
    std::cout << "Before swap: " << a << " " << b << std::endl;
    Swap(pa, pb);
    std::cout << "After swap: " << a << " " << b << std::endl;
    return 0;
}