#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <stdexcept>
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance = 0.0);
    void deposit(double amount);
    void withdraw(double amount);
    double check_balance() const;
};

#endif
