#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(float balance, string fname, string lname, float rate)
    : BaseAccount(balance, fname, lname), interestRate(rate) {}

void SavingsAccount::ApplyInterest() {
    balance += balance * interestRate;
}

void SavingsAccount::Withdraw(float amount) {
    if (balance - amount < 0) {
        cout << "Insufficient balance for savings account" << endl;
    } else {
        balance -= amount;
    }
}

void SavingsAccount::updateBalance() {
    ApplyInterest();
}
