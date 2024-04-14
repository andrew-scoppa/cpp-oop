// Demonstrates the standard mechanism for passing parameters in function calls  

#include <iostream>

struct Point{
    int x = 0;
    int y = 0;
};

void Reset(Point p){
    p.x = 0;
    p.y = 0;
}


int main(){
    Point p;

    std::cout << "Initial values: " << p.x << ", " << p.y << std::endl;

    p.x = 10;
    p.y = 10;

    std::cout << "Before reset: " << p.x << ", " << p.y << std::endl;

    Reset(p);

    std::cout << "After reset: " << p.x << ", " << p.y << std::endl;
}