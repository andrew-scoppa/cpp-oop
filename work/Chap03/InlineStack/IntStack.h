//  IntStack.h
//
//  Integer Stack class, inline version

#include <iostream>
using namespace std;

const int STACKSIZE = 100;

class IntStack              
{
public:
	void InitStack(){ top = 0; }
	void Push(int x){ stack[top++] = x; }
	int Pop() { return stack[--top]; }
	void Print()
	{
		for (int i=top-1; i>=0; --i)
			cout << stack[i] << endl;
	}
private:
	int stack[STACKSIZE];	// stack data
	int top;                // top of stack
};                          
