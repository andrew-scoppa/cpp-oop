#include <iostream>

class foo
{
    int *_data;

public:
    foo(int val = 0) : _data(new int(val))
    {
        //_data = new int(val);
        std::cout << "c'tor" << std::endl;
    }

    ~foo()
    {
        delete _data;
        std::cout << "d'tor" << std::endl;
    }

    void show()
    {
        std::cout << *_data << std::endl;
    }
};

int main()
{

    foo *pfoo[] = {new foo(1), new foo(5), new foo(2), new foo(10)};

    for (foo **p = pfoo; *p != nullptr; ++p)
    {
        (*p)->show();
    }
    // continue using array 

    for (foo **p = pfoo; *p != nullptr; ++p)
    {
        delete *p;
    }
}
