#include <iostream>
#include "array.h"

using namespace std;

int main()
{
	Array<int> array1;
	Array<int> array2(15);
	Array<int> array3;

	long size = array1.size();
	for (int i = 0; i < size; i++)
		array1[i] = i;

	size = array2.size();
	for (int i = size - 1; i >= 0; i--)
		array2[i] = size - i - 1;

	cout << "array1" << endl;
	for (int i = 0; i < 10; i ++)
		cout << array1[i] << endl;

	cout << "array2" << endl;
	for (int i = 0; i < 15; i ++)
		cout << array2[i] << endl;

	cout << "array3" << endl;
	for (int i = 0; i < 10; i ++)
		cout << array3[i] << endl;

	array3 = array1;
	
	cout << "array3" << endl;
	for (int i = 0; i < 10; i ++)
		cout << array3[i] << endl;
}
