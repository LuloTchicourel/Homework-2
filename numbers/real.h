#include "number.h"

class Real : public Number {
    private:
        float value;
    public:
        Real(float v);

        Number* add(const Number& num) const override;
        Number* subtract(const Number& num) const override;
        Number* multiply(const Number& num) const override;
        Number* divide(const Number& num) const override;
        string to_string() const override;

        ~Real() override = default;

        float get_value();
};