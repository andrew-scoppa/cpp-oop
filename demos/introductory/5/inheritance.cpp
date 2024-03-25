#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

struct Point final
{
    int _x;
    int _y;
};

class Shape
{
private:
    Point _loc;
    int _rotation;
public:
    Shape(Point p = Point{0,0}, int rotation = 0) : _loc(p), _rotation(rotation) {
        cout << "Shape c'tor" << endl;
    }

    void Draw() const{
        cout << "Drawing Shape at " << _loc._x << ", " << _loc._y << endl;
        cout << "Rotation angle (degrees) " << _rotation << endl;
    }

    Point Move(Point p){
        Point prev = _loc;
        _loc = p;
        return prev;
    }

    void Rotate(int degrees){
        _rotation = (degrees + _rotation) % 360;
        cout << "Rotating shape " << degrees << " degrees" << endl;

    }

    ~Shape(){
        cout << "Shape d'tor" << endl;
    }
};

class Circle : public Shape{
private:
    double _radius;
public:
    Circle(double radius = 1, Point p = Point{0,0}) : _radius(radius), Shape::Shape(p) {

    }

    // Hides base implementation
    void Draw() const{
        Shape::Draw();
        cout << "Drawing a Circle " << endl;
    }

// TODO refactor for generalization
    double CalcArea(){
        
        return pow(_radius, 2) * M_PI;
    }
};

class Rectangle : public Shape{
private:
    double _length;
    double _width;

public:
    Rectangle(double length = 1, double width = 1) : _length(length), _width(width){

    }
};

int main(){
    Circle c = 10;
    c.Move(Point{10, 20});
    c.Rotate(45);
    c.Draw();

    Circle circles[] = {Circle(10), Circle(20), Circle(20)};
    for (size_t i = 0; i < sizeof(circles) / sizeof(Circle); i++)
    {
       circles[i].Draw();
       cout << "Area of circle " << i+1 << ": " << circles[i].CalcArea() << endl;
    }
    

/*
    Rectangle r,r2;
    r.Move(Point{100, -50});
    r.Rotate(15);
    r.Draw();
*/


}
