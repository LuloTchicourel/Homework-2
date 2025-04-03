#include "complex.h"
#include <sstream>

Complex::Complex(float r, float i){
    real = r; imaginary= i;
}

float Complex::get_real() {return real;}
float Complex::get_imaginary() {return imaginary;}

Number* Complex::add(const Number& num) const {
    const Complex& c = static_cast<const Complex&>(num);
    float r = real + c.real; float i = imaginary + c.imaginary;
    return new Complex(r, i);
}

Number* Complex::subtract(const Number& num) const {
    const Complex& c = static_cast<const Complex&>(num);
    float r = real - c.real; float i = imaginary - c.imaginary;
    return new Complex(r, i);
}

Number* Complex::multiply(const Number& num) const {
    const Complex& c = static_cast<const Complex&>(num);
    float r = real * c.real - imaginary * c.imaginary; 
    float i = real * c.imaginary + imaginary * c.real;
    return new Complex(r, i);
}

Number* Complex::divide(const Number& num) const {
    const Complex& c = static_cast<const Complex&>(num);
    float denominator = c.real * c.real + c.imaginary * c.imaginary;
    if (denominator == 0){
        cout << "Division by 0 is not allowed"; return;
    }
    float r = (real * c.real + imaginary * c.imaginary) / denominator;
    float i = (imaginary * c.real - real * c.imaginary) / denominator;
    return new Complex(r, i);
}

string Complex::to_string() const {
    ostringstream out;
    out << real;
    if (imaginary > 0) out << " + " << imaginary << "i";
    else if (imaginary < 0) out << " - " << -imaginary << "i";
    return out.str();
}