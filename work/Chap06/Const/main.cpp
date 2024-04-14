#include <iostream>
#include "complex.h"

#include <iostream>
#include "complex.h"

void Dump(Complex);

int main(){
    const Complex c(10, 15); 

    Dump(c);

    return 0;
}

void Dump(Complex c){
    c.setImaginary(0);
    c.setReal(0);

    std::cout.precision(4);
    std::cout << "Real: " << c.getReal() << std::endl;
    std::cout << "Imaginary: " << c.getImaginary() << std::endl;
}


