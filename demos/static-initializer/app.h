class Widget
{
    static int _a;

public:
    Widget() {}
    static void set(int a)
    {
        _a = a;
    }
    static int get()
    {
        return _a;
    }
};

int Widget::_a = 0;
