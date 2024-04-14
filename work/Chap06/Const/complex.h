// Specification for a complex user-defined type

class Complex{
public:
    Complex (float = 0, float = 0);
    void setReal(float);
    float getReal() const;	// read-only
    void setImaginary(float);
    float getImaginary() const;	// read-only
private:
    float m_real;
    float m_imaginary;
};


