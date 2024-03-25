// TemplateFunctional.cpp

#include <iostream>
using namespace std;

template <typename T, typename F>
void transform(T *start, T *end, F func, int arg = 1)
{
	T *current;
	current = start;
	while (current != end)
	{
		func(current, arg);
		current++;
	}
}

void Operate(long *value, int arg)
{
	*value = *value + arg;
}

int main()
{

	long x[5] = {1, 3, 4, 2, 5};
	cout << "Before tranform: " << endl;
	for (int i = 0; i < 5; i++)
		cout << x[i] << endl;

	transform(&x[0] /* inclusive start */, &x[5] /* exclusive end */, Operate /* transformation function */, 1 /* optional arg */);
	cout << "After tranform: " << endl;
	for (int i = 0; i < 5; i++)
		cout << x[i] << endl;
}