#include "BankAccount.h"
#include <stdexcept>
#include <iostream>
using namespace std;

BankAccount::BankAccount(double initial_balance) {
    if (initial_balance < 0) throw invalid_argument("Initial balance cannot be negative.");
    balance = initial_balance;
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) throw invalid_argument("Deposit amount must be positive.");
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount > balance) throw runtime_error("Insufficient funds.");
    if (amount <= 0) throw invalid_argument("Withdraw amount must be positive.");
    balance -= amount;
}

double BankAccount::check_balance() const {
    return balance;
    
}