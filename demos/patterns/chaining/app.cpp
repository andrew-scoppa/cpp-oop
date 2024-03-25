/*
Method Chaining is one of the many advantages of using OOPs principle to design a software.
It is a practice of invoking multiple function in one go rather than calling the them separately.
It is also known as Parameter Idiom.
If method chaining is implemented properly it makes the code look more elegant and easier to read. 
*/

#include <iostream>

using namespace std;

class Accumulator
{
private:
    long _value = 0;

public:
    long Get() const
    {
        return _value;
    }
    Accumulator& Add(long value){
        _value += value;
        return *this;
    }
};

int main(){
    Accumulator acc;
    cout << acc.Add(1).Add(2).Add(3).Get() << endl;
}