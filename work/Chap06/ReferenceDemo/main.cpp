// Demonstrates the  mechanism for passing parameters by reference in function calls  

#include <iostream>

/*
struct Point represents a point in a 2D coordinate system.
The x and y coordinates are public members of the struct.
 */
struct Point{
    int x = 0; /* The x coordinate of the point. */
    int y = 0; /* The y coordinate of the point. */
};

void Reset(Point &);

int main(){
    Point p;

    std::cout << "Initial values: " << p.x << ", " << p.y << std::endl;

    p.x = 10;
    p.y = 10;

    std::cout << "Before reset: " << p.x << ", " << p.y << std::endl;

    Reset(p);

    std::cout << "After reset: " << p.x << ", " << p.y << std::endl;
}

/*
 * Resets the coordinates of a Point object to (0, 0).
 * Arguments:
 * The argument p is the Point object to reset.
 */
void Reset(Point &p){
    p.x = 0;
    p.y = 0;
}
