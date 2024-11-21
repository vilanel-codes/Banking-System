#include "Bank.h"

BaseAccount* Bank::OpenAccount(float balance, string fname, string lname, string type) {
    BaseAccount* account = nullptr;
    if (type == "savings") {
        account = new SavingsAccount(balance, fname, lname, 0.05);
    } else if (type == "current") {
        account = new CurrentAccount(balance, fname, lname);
    }
    accounts.insert(make_pair(account->getAccNumber(), account));
    return account;
}

BaseAccount* Bank::BalanceEnquiry(int accnumber) {
    return accounts.find(accnumber)->second;
}

BaseAccount* Bank::Deposit(int accnumber, float amount) {
    BaseAccount* acc = accounts.find(accnumber)->second;
    acc->Deposit(amount);
    return acc;
}

BaseAccount* Bank::Withdraw(int accnumber, float amount) {
    BaseAccount* acc = accounts.find(accnumber)->second;
    acc->Withdraw(amount);
    return acc;
}

void Bank::CloseAccount(int accnumber) {
    auto itr = accounts.find(accnumber);
    cout << "Account Deleted\n" << *(itr->second);
    delete itr->second;
    accounts.erase(accnumber);
}

void Bank::showallaccounts() {
    map<long, BaseAccount*>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++) {
        cout << "Accounts: " << endl << *(itr->second) << endl;
    }
}

void Bank::UpdateAllAccounts() {
    map<long, BaseAccount*>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++) {
        itr->second->updateBalance();  // Update based on the type of account (apply interest or overdraft)
    }
    cout << "All accounts updated successfully." << endl;
}
