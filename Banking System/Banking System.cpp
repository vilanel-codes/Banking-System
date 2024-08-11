// Banking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
using namespace std;
long NextAccNumber = 0;

class Account
{
private:
	int accnumber;
	float balance;
	string firstname;
	string lastname;
public:
	Account() {}
	Account(float balance, string fname, string lname);
	long getAccNumber() { return accnumber; }
	string getfirstname() { return firstname; }
	string getlastname() { return lastname; }
	float getbalance() { return balance; }
	void Deposit(float amount);
	void Withdraw(float amount);
	friend ostream& operator<<(ostream& os, Account& acc);
};
class Bank
{
private:
	map<long, Account> accounts;
public:
	Account OpenAccount(float balance, string fname, string lname);
	Account BalanceEnquiry(int accnumber);
	Account Deposit(int accnumber, float amount);
	Account Withdraw(int accnumber, float amount);
	void CloseAccount(int accnumber);
	void showallaccounts();

};
int main()
{
	int choice;
	int accnumber;
	float balance, amount;
	string fname, lname;
	Account acc;
	Bank b;
	cout << "Welcome to Bank" << endl;
	cout << "How can we help you?" << endl;
	do
	{
		cout << "1.Open Account\n" << "2.Balance Enquiry\n" << "3.Deposit\n" << "4.Withdraw\n" << "5.CLose Account\n" << "6.Show All Accounts\n" << "7.Quit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter First Name: ";
			cin >> fname;
			cout << "Enter Last Name: ";
			cin >> lname;
			cout << "Enter First Balance: ";
			cin >> balance;
			acc = b.OpenAccount(balance, fname, lname);
			cout << endl << "Congratulations Account is Created" << endl;
			cout << acc;
			break;
		case 2:
			cout << "Enter Account Number: ";
			cin >> accnumber;
			acc = b.BalanceEnquiry(accnumber);
			cout << endl << "Your Account Details" << endl;
			cout << acc;
			break;
		case 3:
			cout << "Enter Account Number: ";
			cin >> accnumber;
			cout << "Enter Amount to deposit: ";
			cin >> amount;
			acc = b.Deposit(accnumber, amount);
			cout << endl << "Amount is Deposited" << endl;
			cout << acc;
			break;
		case 4:
			cout << "Enter Account Number: ";
			cin >> accnumber;
			cout << "Enter Amount to withdraw: ";
			cin >> amount;
			acc = b.Withdraw(accnumber, amount);
			cout << endl << "Amount Withdraw" << endl;
			cout << acc;
			break;
		case 5:
			cout << "Enter Account Number: ";
			cin >> accnumber;
			b.CloseAccount(accnumber);
			cout << endl << "Account is Closed" << endl;
			cout << acc;
			break;
		case 6:
			b.showallaccounts();
			break;
		case 7:
			break;
		default:
			cout << "\nEnter your choice: ";
			break;
		}
	} while (choice != 7);
	return 0;

}
Account::Account(float balance, string fname, string lname)
{
	NextAccNumber++;
	accnumber = NextAccNumber;
	this->balance = balance;
	firstname = fname;
	lastname = lname;
}
void Account::Deposit(float amount)
{
	balance += amount;
}
void Account::Withdraw(float amount)
{
	balance -= amount;
}
ostream& operator<<(ostream& os, Account& acc)
{
	os << "Account Number: " << acc.getAccNumber() << endl;
	os << "First Name: " << acc.getfirstname() << endl;
	os << "Lest Name: " << acc.getlastname() << endl;
	os << "Balance: " << acc.getbalance() << endl;
	return os;
}
Account Bank::OpenAccount(float balance, string fname, string lname)
{
	Account account(balance, fname, lname);
	accounts.insert(pair<long, Account>(account.getAccNumber(), account));
	return account;
}
Account Bank::BalanceEnquiry(int accnumber)
{
	map<long, Account>::iterator itr = accounts.find(accnumber);
	return itr->second;
}
Account Bank::Deposit(int accnumber, float amount)
{
	map<long, Account>::iterator itr = accounts.find(accnumber);
	itr->second.Deposit(amount);
	return itr->second;
}
Account Bank::Withdraw(int accnumber, float amount)
{
	map<long, Account>::iterator itr = accounts.find(accnumber);
	itr->second.Withdraw(amount);
	return itr->second;
}
void Bank::CloseAccount(int accnumber)
{
	map<long, Account>::iterator itr = accounts.find(accnumber);
	cout << "Account Deleted\n" << itr->second;
	accounts.erase(accnumber);
}
void Bank::showallaccounts()
{
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		cout << "Accounts: " << endl << itr->second << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
