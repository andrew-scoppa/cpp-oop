#include <iostream>
#include <typeinfo>

using namespace std;

class Widget
{
public:
    void widge() const
    {
    }
};

int foo()
{
    return 0;
}

int main()
{

    const int i = 0;
    decltype(i) i_i = 0;
    cout << typeid(i_i).name() << endl;

    using func = int (*)(); // or typdef int (*func)()
    func f = foo;
    decltype(f) f_x;
    cout << typeid(f_x).name() << endl;

    const Widget *w = new Widget{};
    decltype(w) w_x;
    cout << typeid(w_x).name() << endl;

    Widget ww = Widget{};
    decltype(ww) ww_x;
    cout << typeid(ww_x).name() << endl;

    return 0;
}
