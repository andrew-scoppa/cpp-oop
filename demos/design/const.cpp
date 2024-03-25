#include <iostream>

using namespace std;

class Point {
private:
	int _x, _y;
public:
	Point() {
		cout << "c'tor invoked" << endl;
		_x =  0;
		_y = 0;
	};

	Point(int x, int y) {
		cout << "c'tor invoked" << endl;
		_x = x;
		_y = y;
	};

	int GetX() const {
		return _x;
	}

	int GetY() const {
		return _y;
	}

	void SetX(int x) {
		_x = x;
	}

	void SetY(int y) {
		_y = y;
	}


	~Point() {
		cout << "d'tor invoked" << endl;
	}

};

void Display( const Point& p) {
	cout << p.GetX() << ", " << p.GetY() << endl;
}

int main() {
	Point p(10, 20);

	int x = p.GetX();

	p.SetX(p.GetX() + 1);
	
	Display(p);

}
