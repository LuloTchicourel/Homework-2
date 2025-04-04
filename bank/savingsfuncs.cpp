#include "savings.h"

Savings::Savings(double b, string o, int t) : Account(b, o) {
    reps = t;
}

void Savings::show(){
    reps++;
    if (reps == 2){
        reps = 0;
        cout << "Info shown twice, deducting 20$...\n";
        balance -= 20;
        if (balance < 0){
            balance = 0;
            cout << "Balance became negative. It has been set to zero\n";
        }
    }
    cout << "Account holder: " <<  owner << endl;
    cout << "Savings account balance: " << balance << endl;
}

double Savings::withdraw(double amount, shared_ptr<Savings> savings_account){
    if (savings_account != nullptr){
        cout << "Please do not pass a savings account when withdrawing from one.\n";
        return 0;
    }
    if(amount > balance){
        cout << "Insufficent funds to do the transaction...\n";
        return 0;
    }
    balance -= amount;
    return amount;
}