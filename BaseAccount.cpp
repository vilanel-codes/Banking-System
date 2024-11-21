#include "BaseAccount.h"

long NextAccNumber = 0;

BaseAccount::BaseAccount() {}

BaseAccount::BaseAccount(float balance, string fname, string lname) {
    NextAccNumber++;
    accnumber = NextAccNumber;
    this->balance = balance;
    firstname = fname;
    lastname = lname;
}

void BaseAccount::Deposit(float amount) {
    balance += amount;
}

long BaseAccount::getAccNumber() {
    return accnumber;
}

string BaseAccount::getfirstname() {
    return firstname;
}

string BaseAccount::getlastname() {
    return lastname;
}

float BaseAccount::getbalance() {
    return balance;
}

ostream& operator<<(ostream& os, BaseAccount& acc) {
    os << "Account Number: " << acc.getAccNumber() << endl;
    os << "First Name: " << acc.getfirstname() << endl;
    os << "Last Name: " << acc.getlastname() << endl;
    os << "Balance: " << acc.getbalance() << endl;
    return os;
}
