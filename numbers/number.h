#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number{
    public:
        virtual Number* add(const Number& num) const = 0;
        virtual Number* subtract(const Number& num) const = 0;
        virtual Number* multiply(const Number& num) const = 0;
        virtual Number* divide(const Number& num) const = 0;
        virtual string to_string() const = 0;

        virtual ~Number() = default;
};