#include "stdafx.h"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<char> s;

    s.insert('a');
    s.insert('b');
    s.insert('a');
    s.insert('c');

    for (auto &i : s)
    {
        cout << i << endl;
    }
}