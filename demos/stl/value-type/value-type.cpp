/*
The standard container classes all follow a convention of using explicit nested typedefs
to identify their contained and related types. This allows for the writing of template code
that is generic only over the container type, that in turn infers other types such as the
element and iterator types.
In the example the sum function takes any container type (vector, list, etc.)
holding any element type (int, float, etc.) as a parameter. Using the nested typedefs in
the container, sum extracts the appropriate iterator and element types to do its job.
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template <typename T>
typename T::value_type sum(T &vect)
{
    typename T::iterator it;
    typename T::value_type total = 0;

    for (it = vect.begin(); it != vect.end(); it++)
    {
        total += *it;
    }
    return total;
}

int main()
{

    vector<int> v = {10, 12, 3, 14};
    cout << sum(v) << endl;

    list<double> l;
    l.push_back(5.23);
    l.push_back(4.81);
    l.push_back(8.98);
    l.push_back(4.91);
    cout << sum(l) << endl;

    return 0;
}