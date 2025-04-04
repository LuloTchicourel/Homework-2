#include "account.h"

class Savings : public Account{
private:
    int reps = 0;
public:
    Savings(double b, string o, int t);

    double withdraw(double amount, shared_ptr<Savings> savings_account = {}) override;
    void show() override;
    friend class Checking;
    ~Savings() override = default;
};
