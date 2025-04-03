#include "number.h"

class Complex : public Number {
    private: 
        float real;
        float imaginary;
    public:
        Complex(float r, float i);

        unique_ptr<Number> add(const Number& num) const override;
        unique_ptr<Number> subtract(const Number& num) const override;
        unique_ptr<Number> multiply(const Number& num) const override;
        unique_ptr<Number> divide(const Number& num) const override;
        string to_string() const override;

        ~Complex() override = default;

        float get_real();
        float get_imaginary();
};