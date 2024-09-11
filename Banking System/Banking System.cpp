#include <iostream>
#include <map>
using namespace std;

long NextAccNumber = 0;

// Base class for all account types
class BaseAccount {
protected:
    int accnumber;
    float balance;
    string firstname;
    string lastname;
public:
    BaseAccount() {}
    BaseAccount(float balance, string fname, string lname);
    
    virtual void Deposit(float amount);
    virtual void Withdraw(float amount) = 0;  // Pure virtual function for polymorphism
    virtual void ApplyInterest() = 0;  // Pure virtual function for polymorphism
    long getAccNumber() { return accnumber; }
    string getfirstname() { return firstname; }
    string getlastname() { return lastname; }
    float getbalance() { return balance; }
    virtual void updateBalance() = 0;  // Pure virtual function to update balance based on type
    friend ostream& operator<<(ostream& os, BaseAccount& acc);
};

// Derived class for savings account
class SavingsAccount : public BaseAccount {
private:
    float interestRate;
public:
    SavingsAccount(float balance, string fname, string lname, float rate)
        : BaseAccount(balance, fname, lname), interestRate(rate) {}
    
    void ApplyInterest() override {
        balance += balance * interestRate;  // Apply interest on savings account
    }
    
    void Withdraw(float amount) override {
        if (balance - amount < 0) {
            cout << "Insufficient balance for savings account" << endl;
        } else {
            balance -= amount;
        }
    }

    void updateBalance() override {
        ApplyInterest();  // Automatically apply interest for savings accounts
    }
};

// Derived class for current account
class CurrentAccount : public BaseAccount {
public:
    CurrentAccount(float balance, string fname, string lname)
        : BaseAccount(balance, fname, lname) {}
    
    void ApplyInterest() override {
        // No interest on current accounts
    }
    
    void Withdraw(float amount) override {
        if (balance - amount < -500) {  // Overdraft protection
            cout << "Overdraft limit reached for current account" << endl;
        } else {
            balance -= amount;
        }
    }

    void updateBalance() override {
        // No interest update needed for current accounts
        cout << "Current account balance remains the same (no interest)." << endl;
    }
};

// Bank class for managing accounts
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
    void UpdateAllAccounts();  // Update balances for all accounts
};

// Function implementations
int main() {
    int choice;
    int accnumber;
    float balance, amount;
    string fname, lname, type;
    BaseAccount* acc;
    Bank b;
    cout << "Welcome to Bank" << endl;
    cout << "How can we help you?" << endl;
    do {
        cout << "1.Open Account\n" << "2.Balance Enquiry\n" << "3.Deposit\n" << "4.Withdraw\n" << "5.Close Account\n" << "6.Show All Accounts\n" << "7.Update All Accounts (Apply Interest/Overdraft)\n" << "8.Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter First Balance: ";
            cin >> balance;
            cout << "Account Type (savings/current): ";
            cin >> type;
            acc = b.OpenAccount(balance, fname, lname, type);
            cout << endl << "Congratulations! Account is Created" << endl;
            cout << *acc;
            break;
        case 2:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            acc = b.BalanceEnquiry(accnumber);
            cout << endl << "Your Account Details" << endl;
            cout << *acc;
            break;
        case 3:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            cout << "Enter Amount to deposit: ";
            cin >> amount;
            acc = b.Deposit(accnumber, amount);
            cout << endl << "Amount Deposited" << endl;
            cout << *acc;
            break;
        case 4:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            cout << "Enter Amount to withdraw: ";
            cin >> amount;
            acc = b.Withdraw(accnumber, amount);
            cout << endl << "Amount Withdrawn" << endl;
            cout << *acc;
            break;
        case 5:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            b.CloseAccount(accnumber);
            cout << endl << "Account Closed" << endl;
            break;
        case 6:
            b.showallaccounts();
            break;
        case 7:
            b.UpdateAllAccounts();
            break;
        case 8:
            break;
        default:
            cout << "\nEnter a valid choice: ";
            break;
        }
    } while (choice != 8);
    return 0;
}

// BaseAccount constructor
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

// Operator overloading for account output
ostream& operator<<(ostream& os, BaseAccount& acc) {
    os << "Account Number: " << acc.getAccNumber() << endl;
    os << "First Name: " << acc.getfirstname() << endl;
    os << "Last Name: " << acc.getlastname() << endl;
    os << "Balance: " << acc.getbalance() << endl;
    return os;
}

// Bank class methods
BaseAccount* Bank::OpenAccount(float balance, string fname, string lname, string type) {
    BaseAccount* account = nullptr;
    if (type == "savings") {
        account = new SavingsAccount(balance, fname, lname, 0.05);  // 5% interest rate for savings
    } else if (type == "current") {
        account = new CurrentAccount(balance, fname, lname);
    }
    accounts.insert(make_pair(account->getAccNumber(), account));
    return account;
}

BaseAccount* Bank::BalanceEnquiry(int accnumber) {
    map<long, BaseAccount*>::iterator itr = accounts.find(accnumber);
    return itr->second;
}

BaseAccount* Bank::Deposit(int accnumber, float amount) {
    map<long, BaseAccount*>::iterator itr = accounts.find(accnumber);
    itr->second->Deposit(amount);
    return itr->second;
}

BaseAccount* Bank::Withdraw(int accnumber, float amount) {
    map<long, BaseAccount*>::iterator itr = accounts.find(accnumber);
    itr->second->Withdraw(amount);
    return itr->second;
}

void Bank::CloseAccount(int accnumber) {
    map<long, BaseAccount*>::iterator itr = accounts.find(accnumber);
    cout << "Account Deleted\n" << *(itr->second);
    delete itr->second;  // Free the allocated memory
    accounts.erase(accnumber);
}

void Bank::showallaccounts() {
    map<long, BaseAccount*>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++) {
        cout << "Accounts: " << endl << *(itr->second) << endl;
    }
}

// Update all accounts
void Bank::UpdateAllAccounts() {
    map<long, BaseAccount*>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++) {
        itr->second->updateBalance();  // Update based on the type of account (apply interest or overdraft)
    }
    cout << "All accounts updated successfully." << endl;
}
