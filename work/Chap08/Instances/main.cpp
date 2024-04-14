// Demonstrates using static to count the number of instances in use.
// This is not the same as reference counting!

#include <iostream>
#include <cassert>
#include "Widget.h"

using std::cout, std::endl;

long Widget::m_instances = 0;

int main()
{
    assert(Widget::GetInstances() == 0);

    Widget w1;
    assert(Widget::GetInstances() == 1);

    Widget w2 = w1;
    assert(Widget::GetInstances() == 2);

    { // nested scope
        Widget w3;
        assert(Widget::GetInstances() == 3);
    }
    assert(Widget::GetInstances() == 2);

    cout << "If you see this message it works!" << endl;
}
