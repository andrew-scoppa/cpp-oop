#include <iostream>

class Linear
{
private:
    double _a, _b;
public:
    Linear(double a, double b) : _a(a), _b(b){};
    
    // functor method to apply x and y to a and b
    double operator()(double x, double y) const{
        return _a * x + _b * y;
    }
};

template <typename LinearFunc>
void combine(double a[], double b[], double c[], int n, LinearFunc fn)
{
    for (int i = 0; i < n; i++)
        c[i] = fn(a[i], b[i]);
}

double Product(double x, double y)
{
    return x * y;
}

int main()
{
    const int size = 5;
    double x[size]{1.0, 2.0, 3.0, 4.0, 5.0};
    double y[size]{6.0, 7.0, 8.0, 9.0, 10.0};
    double z[size];

    combine(x, y, z, size, Linear(1,2) /* set Linear::_a == 1, Linear::_b == 2 */);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << z[i] << std::endl;
    }
}