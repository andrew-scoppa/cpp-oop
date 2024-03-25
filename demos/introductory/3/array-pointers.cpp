#include <iostream>

class Widget
{
    int *_data;

public:
    Widget(int val = 0) : _data(new int(val))
    {

        std::cout << "c'tor" << std::endl;
    }

    ~Widget()
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

    Widget *ar[] = {new Widget(1), new Widget(5), new Widget(2), new Widget(10)};

    const size_t count = sizeof(ar) / sizeof(*ar);

    for (Widget **it = ar; it < (ar + count); ++it)
    {
        (*it)->show();
    }

    // continue using array

    for (Widget **it = ar; it != (ar + count); ++it)
    {
        delete *it;
    }

}
