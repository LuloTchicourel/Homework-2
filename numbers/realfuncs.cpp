#include "real.h"

Real::Real(float v) {value = v;}

float Real::get_value() {return value;}

unique_ptr<Number> Real::add(const Number& num) const {
    const Real& n = static_cast<const Real&>(num);
    return make_unique<Real>(value + n.value);
}

unique_ptr<Number> Real::subtract(const Number& num) const {
    const Real& n = static_cast<const Real&>(num);
    return make_unique<Real>(value - n.value);
}

unique_ptr<Number> Real::multiply(const Number& num) const {
    const Real& n = static_cast<const Real&>(num);
    return make_unique<Real>(value * n.value);
}

unique_ptr<Number> Real::divide(const Number& num) const {
    const Real& denominator = static_cast<const Real&>(num);
    if (denominator.value == 0){
        cout << "Division by 0 is not allowed\n"; return nullptr;
    }
    return make_unique<Real>(value / denominator.value);
}

string Real::to_string() const {
    return std::to_string(value);
}