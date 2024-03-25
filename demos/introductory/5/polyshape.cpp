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

    virtual double CalcArea(){

        return 0;
    }

    virtual void Draw() const{
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

    virtual ~Shape(){
        cout << "Shape d'tor" << endl;
    }
};

class Circle : public Shape{
private:
    double _radius;
public:
    Circle(double radius = 1, Point p = Point{0,0}) : _radius(radius), Shape::Shape(p) {

    }

    // overide base implementation
    void Draw() const override{
        Shape::Draw();
        cout << "Drawing a Circle " << endl;
    }

    double CalcArea() override{
        
        return pow(_radius, 2) * M_PI;
    }

    ~Circle(){
        cout << "Circle d'tor" << endl;
    }
};

class Rectangle : public Shape{
private:
    double _length;
    double _width;

public:
    Rectangle(double length = 1, double width = 1) : _length(length), _width(width){

    }

    void Draw() const{
        Shape::Draw();
        cout << "Drawing a Square " << endl;
    }

    ~Rectangle(){
        cout << "Rectangle d'tor" << endl;
    }
};

int main(){

    Shape *pShapes[] = {new Circle(10),  new Rectangle(50), nullptr};

    for (Shape **p = pShapes;  *p != nullptr; ++ p){
        (*p)->Draw();
    }

    //...

    for (Shape **p = pShapes;  *p != nullptr; ++ p){
        delete *p;
    }

}
