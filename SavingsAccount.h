#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BaseAccount.h"

class SavingsAccount : public BaseAccount {
private:
    float interestRate;

public:
    SavingsAccount(float balance, string fname, string lname, float rate);
    void ApplyInterest() override;
    void Withdraw(float amount) override;
    void updateBalance() override;
};

#endif
