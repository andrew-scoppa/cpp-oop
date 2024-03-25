// Demonstrates using static to count the number of instances in use.
// This is not the same as reference counting!

#include <iostream>
#include <assert.h>

using namespace std;

class Widget
{
public:
    Widget()
    {
        ++m_instances;
    }
    Widget(const Widget &)
    {
        ++m_instances;
    }
    ~Widget()
    {
        --m_instances;
    }
    static long GetInstances()
    {
        return m_instances;
    }

private:
    static long m_instances;
};
long Widget::m_instances = 0;

int main()
{
    assert(Widget::GetInstances() == 0);

    Widget w1;
    assert(Widget::GetInstances() == 1);

    Widget w2 = w1;
    assert(Widget::GetInstances() == 2);

    {
        Widget w3;
        assert(Widget::GetInstances() == 3);
    }
    assert(Widget::GetInstances() == 2);

    cout << "If you see this message it works!" << endl;
}
