#include <iostream>
#include <string>
using namespace std;

void inc(int n)
{
    ++n;
    cout << "In inc() " << n << endl;
}

void inc(int* pn)
{
    ++(*pn);
    cout << "In inc() " << *pn << endl;
}


int main()
{

    int a = 2;
    cout << "In main() before call " << a << endl;
    inc(&a);
    cout << "In main() after call " << a << endl;

    return 0;
}
