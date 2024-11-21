#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "BaseAccount.h"

class CurrentAccount : public BaseAccount {
public:
    CurrentAccount(float balance, string fname, string lname);
    void ApplyInterest() override;
    void Withdraw(float amount) override;
    void updateBalance() override;
};

#endif
