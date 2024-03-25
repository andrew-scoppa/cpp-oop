#include <iostream>

class foo
{
    int *_data;

public:
    foo()
    {
        _data = new int;
        std::cout << "c'tor" << std::endl;
    }

    ~foo()
    {
        delete _data;
        std::cout << "d'tor" << std::endl;
    }
};

int main()
{

    foo *p;

    p = new foo[1];

    delete[] p;
    p = nullptr;

    p = new foo;

    delete p;
    p = nullptr;
}
