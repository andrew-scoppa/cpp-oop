// List.cpp

#include <list>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int a[] = {1, 2, 3, 4, 5};
	int n;

	list<int> lst(a, a + sizeof(a) / sizeof(int));

	list<int>::iterator lstart = lst.begin();
	list<int>::iterator lfinish = lst.end();
	list<int>::iterator lwhere;

	cout << "Start: " << *lstart << endl;
	cout << "finish: " << *(lfinish ) << endl;

	cout << "Enter a number to find: ";
	cin >> n;

	lwhere = find(lstart, lfinish, n);
	if (lwhere != lfinish)
		cout << "Found list: " << *lwhere << '\n';
	else
		cout << "Not found in list: "<< *lwhere << '\n';

	return 0;
}
