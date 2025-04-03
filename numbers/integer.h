#include "number.h"

class Integer : public Number {
    private: 
        int value;
    public:
        Integer(int v);

        unique_ptr<Number> add(const Number& num) const override;
        unique_ptr<Number> subtract(const Number& num) const override;
        unique_ptr<Number> multiply(const Number& num) const override;
        unique_ptr<Number> divide(const Number& num) const override;
        string to_string() const override;

        ~Integer() override = default;

        int get_value();
};