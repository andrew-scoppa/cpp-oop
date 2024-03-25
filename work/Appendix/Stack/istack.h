//  istack.hpp
//
//  Specification of Integer Stack class, fixed size array.

const int STACKSIZE = 100;

class IntStack          // IntStack is tag-name
{
public:
    IntStack();         // constructor
    void Push(int x);
    int Pop();
    void Print();
private:
    int st[STACKSIZE];      // stack data
    int sp;                 // stack pointer
};
