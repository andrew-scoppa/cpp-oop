#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Predicate
{
    void operator()(int n) const {
        cout << n;

        if (n % 2 == 0) {
            cout << " is even " << endl;
        } else {
            cout << " is odd " << endl;
        }
    }

};

int main()
{
    const int Max = 10;

    vector<int> v;
    for (int i = 1; i <= Max; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), Predicate());
}