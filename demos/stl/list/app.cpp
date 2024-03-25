// doubly-linked list
#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    std::list<char> l;

    l.push_back('a');
    l.push_back('b');

    l.push_front('z');
    l.push_front('y');

    for (auto const&i : l)
    {
        cout << i ;
    }
    cout << endl;

    return 0;
}