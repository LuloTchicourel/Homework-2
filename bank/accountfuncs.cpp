#include "account.h"

Account::Account(double b, string o){
    balance = b; owner = o;
}

void Account::deposit(double amount){
    balance += amount;
}