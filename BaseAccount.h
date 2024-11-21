#ifndef BASE_ACCOUNT_H
#define BASE_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BaseAccount {
protected:
    int accnumber;
    float balance;
    string firstname;
    string lastname;

public:
    BaseAccount();
    BaseAccount(float balance, string fname, string lname);
    virtual void Deposit(float amount);
    virtual void Withdraw(float amount) = 0;
    virtual void ApplyInterest() = 0;
    long getAccNumber();
    string getfirstname();
    string getlastname();
    float getbalance();
    virtual void updateBalance() = 0;
    friend ostream& operator<<(ostream& os, BaseAccount& acc);
};

#endif
