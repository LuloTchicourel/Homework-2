#include "account.h"

class Checking : public Account{  
public:
    Checking(float b, string o);

    double withdraw(double amount, shared_ptr<Savings> savings_account) override;
    void show() override;
};