#include "Bank.h"

int main() {
    int choice, accnumber;
    float balance, amount;
    string fname, lname, type;
    BaseAccount* acc;
    Bank b;

    cout << "Welcome to Bank" << endl;
    do {
        cout << "1. Open Account\n"
             << "2. Balance Enquiry\n"
             << "3. Deposit\n"
             << "4. Withdraw\n"
             << "5. Close Account\n"
             << "6. Show All Accounts\n"
             << "7. Update All Accounts\n"
             << "8. Quit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter Initial Balance: ";
            cin >> balance;
            cout << "Account Type (savings/current): ";
            cin >> type;
            acc = b.OpenAccount(balance, fname, lname, type);
            cout << "Account Created\n" << *acc << endl;
            break;
        case 2:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            acc = b.BalanceEnquiry(accnumber);
            cout << "Account Details:\n" << *acc << endl;
            break;
        case 3:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            acc = b.Deposit(accnumber, amount);
            cout << "Deposit Successful\n" << *acc << endl;
            break;
        case 4:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            acc = b.Withdraw(accnumber, amount);
            cout << "Withdrawal Successful\n" << *acc << endl;
            break;
        case 5:
            cout << "Enter Account Number: ";
            cin >> accnumber;
            b.CloseAccount(accnumber);
            cout << "Account Closed" << endl;
            break;
        case 6:
            b.showallaccounts();
            break;
        case 7:
            b.UpdateAllAccounts();
            break;
        case 8:
            cout << "Thank you for banking with us!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
