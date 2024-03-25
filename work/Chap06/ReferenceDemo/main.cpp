// Demonstrates the  mechanism for passing parameters by reference in function calls  

#include <iostream>

using namespace std;

struct Point{
    int x = 0;
    int y = 0;
};

void Reset(Point &);

int main(){
    Point p;

    cout << "Initial values: " << p.x << ", " << p.y << endl;

    p.x = 10;
    p.y = 10;

    cout << "Before reset: " << p.x << ", " << p.y << endl;

    Reset(p);

    cout << "After reset: " << p.x << ", " << p.y << endl;
}

void Reset(Point &p){
    p.x = 0;
    p.y = 0;
}
