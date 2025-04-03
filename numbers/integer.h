#include "number.h"

using namespace std;

class Integer : public Number {
    private:
        int value;
    public:
        Integer(int value);

        Number* add(const Number& other) const override;
        Number* subtract(const Number& other) const override;
        Number* multiply(const Number& other) const override;
        Number* divide(const Number& other) const override;
};