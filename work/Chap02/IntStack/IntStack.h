//  IntStack.h
//
//  Specification of Integer Stack class

int const STACKSIZE = 100;

class IntStack              		// IntStack is tag-name
{
public:
	void InitStack();            
	void Push(int x);
	int Pop();
	void Print();
	
private:
	int _top = 0;                	// top of stack
	int _stack[STACKSIZE];			// stack array

};                          		// semicolon required!!!
