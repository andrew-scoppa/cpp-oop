#include <iostream>
#include "complex.h"

using namespace std;

void Dump(Complex);

int main(){
    const Complex c(10, 15); 

    Dump(c);

    return 0;
}

// TODO
// Change formal argument to const than recompile
void Dump(Complex c){
    // This is legal! Why?
    c.setImaginary(0);
    c.setReal(0);

    cout.precision(4); // manipuator instructing the cout object to show precision of 4
    cout << "Real: " << c.getReal() << endl;
    cout << "Imaginary: " << c.getImaginary() << endl;
}
