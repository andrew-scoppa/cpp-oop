#include <iostream>

using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0) : _x(x), _y(y){   };
    int getX() const
    {
        return _x;
    }
    int getY() const
    {
        return _y;
    }
    void setX(int x)
    {
        _x = x;
    }
    void setY(int y)
    {
        _y = y;
    }

private:
    int _x;
    int _y;
};

ostream &operator<<(ostream &os, Point p)
{
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

template <typename T>
T const &maximum(T const &a, T const &b)
{
    return a > b ? a : b;
}

Point maximum(Point const &a, Point const &b)
{
    Point c;
    c.setX(maximum(a.getX(), b.getX()));
    c.setY(maximum(a.getY(), b.getY()));
    return c;
}

int main()
{

    int a = 10, b = 20;
    cout << maximum(a, b) << endl;

    float c = 10, d = 20;
    cout << maximum(c, d) << endl;

    Point p = Point{25, 15}, q = Point{11, 55};
    Point r = maximum(p, q);
    cout << r << endl;

    return 0;
}
