#include "complex.h"

Complex::Complex(float real, float imaginary){
    m_real = real;
    m_imaginary = imaginary;
}

float Complex::getReal() const{
    return m_real;
}

float Complex::getImaginary() const{
    return m_imaginary;
}

void Complex::setReal(float real){
    m_real = real;
}

void Complex::setImaginary(float imaginary){
    m_imaginary = imaginary;
}