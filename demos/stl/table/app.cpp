#include "stdafx.h"
#include <iostream>
#include <map>
#include <limits>
#include <cmath>

using namespace std;

float input[5][2]{
    {-4, 5},
    {0, 3},
    {4, 8},
    {1, -4},
    {10, 0},
};

using func = float (*)(float, float);

float add(float a, float b) {
    return a + b;
}

float sub(float a, float b) {

    return a - b;
}

int main()
{

    map<char, func> m;
    m['+'] = add; 
    m['-'] = sub;
    m['*'] = [](float a, float b) -> float { return a * b; };
    m['/'] = [](float a, float b) -> float { return b == 0 ? numeric_limits<float>::max() : a / b; };
    m['^'] = [](float a, float b) -> float { return pow(a, b); };

    for (auto row : input)
    {

        float lhs = row[0], rhs = row[1];
        cout << lhs << " + " << rhs << " = " << m['+'](lhs, rhs) << endl;
        cout << lhs << " - " << rhs << " = " << m['-'](lhs, rhs) << endl;
        cout << lhs << " * " << rhs << " = " << m['*'](lhs, rhs) << endl;
        cout << lhs << " / " << rhs << " = " << m['/'](lhs, rhs) << endl;

        cout << lhs << "^ " << rhs << " = " << m['^'](lhs, rhs) << endl;

        cout << endl;
    }
    return 0;
}
