#include "stdafx.h
#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

int main()
{
    
	vector<int> v = { 1,2,3,4,5 };

	for (vector<int>::size_type i = 0; i != v.size(); i++) {
		cout << v[i] << endl;
	}

    for_each(v.begin(), v.end(),[](int n){
		cout << n * 5 << endl;
    });

	for (auto const& value : v) {
		cout << value * 10 << endl;

	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}

