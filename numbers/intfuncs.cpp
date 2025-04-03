#include "integer.h"

Integer::Integer(int v) {value = v;}

int Integer::get_value() {return value;}

unique_ptr<Number> Integer::add(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return make_unique<Integer>(value + n.value);
}

unique_ptr<Number> Integer::subtract(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return make_unique<Integer>(value - n.value);
}

unique_ptr<Number> Integer::multiply(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return make_unique<Integer>(value * n.value);
}

unique_ptr<Number> Integer::divide(const Number& num) const {
    const Integer& denominator = static_cast<const Integer&>(num);
    if (denominator.value == 0){
        cout << "Division by 0 is not allowed\n"; return nullptr;
    }
    return make_unique<Integer>(value / denominator.value);
}

string Integer::to_string() const {
    return std::to_string(value);
}