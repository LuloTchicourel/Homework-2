#include "number.h"

class Integer : public Number {
    private: 
        int value;
    public:
        Integer(int v);

        Number* add(const Number& num) const override;
        Number* subtract(const Number& num) const override;
        Number* multiply(const Number& num) const override;
        Number* divide(const Number& num) const override;
        string to_string() const override;

        ~Integer() override = default;

        int get_value();
};