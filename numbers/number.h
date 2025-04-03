#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number{
    public:
        virtual Number* sum(const Number& num) const = 0;
        virtual Number* subtract(const Number& num) = 0;
        virtual Number* multiply(const Number& num) = 0;
        virtual Number* divide(const Number& num) = 0;
        virtual string to_string();
        virtual ~Number() {};
};