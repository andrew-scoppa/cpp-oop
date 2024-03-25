#include <iostream>
using namespace std;

struct Point
{
	Point(int x_loc = 0, int y_loc = 0) : x(x_loc), y(y_loc) {}
	int x, y;
};

class Shape
{
private:
	Point _loc;

protected:
	void SetLocation(Point loc)
	{
		_loc = loc;
	}

public:

	Shape(Point p = Point{0, 0}) : _loc(p)
	{
		cout << "Shape c'tor" << endl;
	}

	void Render() const
	{
		cout << "Rendering shape..." << endl;
	}

	Point GetLocation()
	{
		return _loc;
	}
	~Shape()
	{
		cout << "Shape d'tor" << endl;
	}
};

class Circle : public Shape
{
	int _radius;


public:

	Circle(int radius, Point loc) : _radius(radius), Shape::Shape(loc)
	{

		cout << "Circle c'tor" << endl;
	}

	~Circle()
	{
		cout << "Circle d'tor" << endl;
	}

	void Resize(int radius)
	{
		_radius = radius;
	}
	void Render() const
	{
		cout << "Rendering circle..." << endl;
	}
};

int main()
{

	Shape *p[] = {new Circle(1, Point(0, 0))};
	for(Shape** it = p; it < p + sizeof(p)/ sizeof(Shape*); ++it){
		(*it)->Render();
	}

	for (Shape** it = p; it < p + sizeof(p) / sizeof(Shape*); ++it) {
		delete* it;
		*it = nullptr;
	}

	return 0;
}
