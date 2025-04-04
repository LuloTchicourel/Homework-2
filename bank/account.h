#pragma once
#include <iostream>
#include <string>
#include <memory>

class Savings;

using namespace std;

class Account{
protected: // utilizo protected debido a que permite que las funciones que heredan puedan acceder
    double balance;
    string owner;
public:
    Account(double b, string o);

    void deposit(double amount);
    virtual double withdraw(double amount, shared_ptr<Savings> savings_account = nullptr) = 0;
    virtual void show() = 0;

    virtual ~Account() = default;
};