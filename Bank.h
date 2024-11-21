#ifndef BANK_H
#define BANK_H

#include "BaseAccount.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <map>

class Bank {
private:
    map<long, BaseAccount*> accounts;

public:
    BaseAccount* OpenAccount(float balance, string fname, string lname, string type);
    BaseAccount* BalanceEnquiry(int accnumber);
    BaseAccount* Deposit(int accnumber, float amount);
    BaseAccount* Withdraw(int accnumber, float amount);
    void CloseAccount(int accnumber);
    void showallaccounts();
    void UpdateAllAccounts();
};

#endif
