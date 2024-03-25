/*
When using functions, thread parameters are passed in a comma separated list.  
For lambdas, use standard syntax: parameters or captured variables.

*/
#include <iostream>
#include <thread>

using namespace std;

void Func(int a, int b){
	cout << a + b;
}
int main() {
	int i = 2;
	thread t1{ Func, i, i + 5 };
	thread t2{ [=] {cout << i; } };
	t1.join();
	t2.join();
    	return 0;
}
