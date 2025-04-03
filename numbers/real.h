#include "number.h"

class Real : public Number {
    private:
        float value;
    public:
        Real(float v);

        unique_ptr<Number> add(const Number& num) const override;
        unique_ptr<Number> subtract(const Number& num) const override;
        unique_ptr<Number> multiply(const Number& num) const override;
        unique_ptr<Number> divide(const Number& num) const override;
        string to_string() const override;

        ~Real() override = default;

        float get_value();
};