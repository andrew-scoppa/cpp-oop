#include <iostream>
#include <vector>

class Widget
{
    int *_data;

public:
    Widget(int val = 0) : _data(new int(val))
    {

        std::cout << "c'tor" << std::endl;
    }
    Widget(const Widget &other)
    {
        _data = new int(*other._data);
        std::cout << "copy c'tor" << std::endl;
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

class WidgetContainer
{
public:
    std::vector<Widget *> _ar;

public:
    WidgetContainer()
    {
    }
    WidgetContainer(std::initializer_list<Widget *> l) : _ar(l)
    {
        std::cout << "Container init"
                  << std::endl;
    }

    void insert_end(const Widget &w)
    {
        _ar.push_back(new Widget(w));
    }
    void insert_end(int n)
    {
        _ar.push_back(new Widget(n));
    }

    void render()
    {
        std::vector<Widget *>::iterator it;
        for (it = _ar.begin(); it < _ar.end(); ++it)
        {
            (*it)->show();
        }
    }

    ~WidgetContainer()
    {
        std::vector<Widget *>::iterator it;
        for (it = _ar.begin(); it < _ar.end(); ++it)
        {
            delete *it;
        }

        std::cout
            << "Container destroyed"
            << std::endl;
    };
};
int main()
{

    WidgetContainer w{new Widget(1), new Widget(5), new Widget(10), new Widget(20)};

    w.insert_end(Widget(30));
    w.insert_end(Widget(40));
    w.insert_end(50);
    w.insert_end(Widget(100));

    w.render();
}
