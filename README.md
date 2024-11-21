# Banking System Application

A simple console-based banking system built in C++ that allows users to create and manage savings and current accounts. The application supports basic banking functionalities like deposits, withdrawals, interest application, and account management.

---

## Features
- **Account Types:**
  - Savings Accounts (with interest rates).
  - Current Accounts (with overdraft protection).
- **Functionalities:**
  - Open new accounts.
  - Deposit and withdraw funds.
  - View account details.
  - Close accounts.
  - Update all accounts (apply interest or manage overdraft limits).
  - Display all active accounts.

---

## Project Structure

```plaintext
banking-system/
├── main.cpp               # Entry point for the application
├── BaseAccount.h          # Header file for BaseAccount class
├── BaseAccount.cpp        # Implementation of BaseAccount methods
├── SavingsAccount.h       # Header file for SavingsAccount class
├── SavingsAccount.cpp     # Implementation of SavingsAccount methods
├── CurrentAccount.h       # Header file for CurrentAccount class
├── CurrentAccount.cpp     # Implementation of CurrentAccount methods
├── Bank.h                 # Header file for Bank class
├── Bank.cpp               # Implementation of Bank methods
└── README.md              # Project documentation (this file)
```

---

## How to Run
- Prerequisites:
A C++ compiler (e.g., GCC or Clang).
(Optional) Git for cloning the repository.
Steps to Compile and Run
Clone the repository:
```plaintext
git clone https://github.com/your-username/banking-system.git
cd banking-system
```

- Compile the program:
```plaintext
g++ -o bank_app main.cpp BaseAccount.cpp SavingsAccount.cpp CurrentAccount.cpp Bank.cpp
```
- Run the executable:
```plaintext
./bank_app  # On Linux/macOS
bank_app    # On Windows
```
