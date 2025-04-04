#include "checking.h"
#include "savings.h"

Checking::Checking(float b, string o) : Account(b, o) {}

double Checking::withdraw(double amount, shared_ptr<Savings> savings_account){
    if (balance >= amount){
        balance -= amount;
        return amount;
    } 
    else if (savings_account && savings_account->balance >= amount - balance){
        double savings_money = amount - balance;
        balance = 0;
        savings_account->balance -= savings_money;
        return amount;
    } 
    else {
        cout << "Not enough funds in checking or linked savings account.\n";
        return 0;
    }
}

void Checking::show(){
    cout << "Account holder: " << owner << endl; 
    cout << "Checking account balance: " << balance << endl;
}