#pragma once
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Number{
    public:
        virtual unique_ptr<Number> add(const Number& num) const = 0;
        virtual unique_ptr<Number> subtract(const Number& num) const = 0;
        virtual unique_ptr<Number> multiply(const Number& num) const = 0;
        virtual unique_ptr<Number> divide(const Number& num) const = 0;
        virtual string to_string() const = 0;

        virtual ~Number() = default;
};