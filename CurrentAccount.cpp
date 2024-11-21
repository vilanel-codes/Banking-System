#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(float balance, string fname, string lname)
    : BaseAccount(balance, fname, lname) {}

void CurrentAccount::ApplyInterest() {
    // No interest for current accounts
}

void CurrentAccount::Withdraw(float amount) {
    if (balance - amount < -500) {
        cout << "Overdraft limit reached for current account" << endl;
    } else {
        balance -= amount;
    }
}

void CurrentAccount::updateBalance() {
    cout << "Current account balance remains the same (no interest)." << endl;
}
