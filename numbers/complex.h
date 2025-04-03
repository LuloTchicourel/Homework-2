#include "number.h"

class Complex : public Number {
    private: 
        float real;
        float imaginary;
    public:
        Complex(float r, float i);

        Number* add(const Number& num) const override;
        Number* subtract(const Number& num) const override;
        Number* multiply(const Number& num) const override;
        Number* divide(const Number& num) const override;
        string to_string() const override;

        ~Complex() override = default;

        float get_real();
        float get_imaginary();
};