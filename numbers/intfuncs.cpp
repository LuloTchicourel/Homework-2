#include "integer.h"

Integer::Integer(int v) {value = v;}

int Integer::get_value() {return value;}

Number* Integer::add(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return new Integer(value + n.value);
}

Number* Integer::subtract(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return new Integer(value - n.value);
}

Number* Integer::multiply(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return new Integer(value * n.value);
}

Number* Integer::divide(const Number& num) const {
    const Integer& n = static_cast<const Integer&>(num);
    return new Integer(value / n.value);
}

string Integer::to_string() const {
    return std::to_string(value);
}