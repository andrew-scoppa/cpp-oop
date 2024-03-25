#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

class IRender
{
public:
    virtual void Draw() const = 0;
    virtual ~IRender(){}
};

class ITransform
{
public:
    virtual void Rotate(int) = 0;
    virtual ~ITransform(){}
};

struct Point final
{
    int _x;
    int _y;
};

class Shape : public IRender, public ITransform
{
private:
    Point _loc;
    int _rotation;

public:
    Shape(Point p = Point{0, 0}, int rotation = 0) : _loc(p), _rotation(rotation)
    {
        cout << "Shape c'tor" << endl;
    }

    virtual double CalcArea() = 0;

    void Draw() const
    {
        cout << "Drawing Shape at " << _loc._x << ", " << _loc._y << endl;
        cout << "Rotation angle (degrees) " << _rotation << endl;
    }

    Point Move(Point p)
    {
        Point prev = _loc;
        _loc = p;
        return prev;
    }

    void Rotate(int degrees)
    {
        _rotation = (degrees + _rotation) % 360;
        cout << "Rotating shape " << degrees << " degrees" << endl;
    }

    virtual ~Shape()
    {
        cout << "Shape d'tor" << endl;
    }
};

class Circle : public Shape
{
private:
    double _radius;

public:
    Circle(double radius = 1, Point p = Point{0, 0}) : _radius(radius), Shape::Shape(p)
    {
    }

    void Draw() const override
    {
        Shape::Draw();
        cout << "Drawing a Circle " << endl;
    }

    double CalcArea() override
    {
        return pow(_radius, 2) * M_PI;
    }

    ~Circle()
    {
        cout << "Circle d'tor" << endl;
    }
};

class Rectangle : public Shape
{
private:
    double _length;
    double _width;

public:
    Rectangle(double length = 1, double width = 1) : _length(length), _width(width)
    {
    }

    double CalcArea() override
    {
        return _length * _width;
    }

    void Draw() const
    {
        Shape::Draw();
        cout << "Drawing a Square " << endl;
    }

    ~Rectangle()
    {
        cout << "Rectangle d'tor" << endl;
    }
};
// TODO Change Shape to IDraw
int main()
{

    IRender *pShapes[] = {new Circle(10), new Rectangle(50)};

    for (IRender **p = pShapes; 
    p < pShapes +  sizeof(pShapes) / sizeof(IRender); ++p)
    {
        (*p)->Draw();
    }

    //...

    for (IRender **p = pShapes; 
    p < pShapes +  sizeof(pShapes) / sizeof(IRender); ++p)
    {
        delete *p;
        p = nullptr;
    }
}
