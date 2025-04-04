#include "savings.h"
#include "checking.h"
#include <memory>

int main() {
    shared_ptr<Savings> savings = make_shared<Savings>(100.0, "Alice", 0);
    Checking checking(50.0, "Alice");

    cout << "\n=== Initial Info ===\n";
    savings->show(); cout << "\n";
    checking.show(); cout << "\n";

    cout << "\n=== Withdraw from Checking (Insufficient) ===\n";
    double withdrawn = checking.withdraw(70.0, savings);  
    cout << "Withdrawn: $" << withdrawn << "\n";

    cout << "\n=== After Withdrawal ===\n";
    savings->show(); cout << "\n";
    checking.show(); cout << "\n";

    cout << "\n=== Trigger Savings Penalty ===\n";
    savings->show(); cout << "\n";
    savings->show(); cout << "\n";  

    cout << "\n=== Direct Savings Overdraw Attempt ===\n";
    savings->withdraw(999);

    return 0;
}