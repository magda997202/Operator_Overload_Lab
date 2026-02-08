#include "BankAccount.h"
#include <iostream>
#include <string>
#include <limits>
#include <utility>

using namespace std;

// Default constructor
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
}

// Parameterized constructor
BankAccount::BankAccount(string number, string name, double initialBalance) {
    accountNumber = std::move(number);
    accountHolderName = std::move(name);
    balance = initialBalance;
}

// Copy constructor (Rule of Three)
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}

// Copy assignment operator (Rule of Three)
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}

// Destructor (Rule of Three)
BankAccount::~BankAccount() {
    // Nothing special to clean up since we're using std::string
}

// Accessors
string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

// Mutator
void BankAccount::setAccountHolderName(string newName) {
    accountHolderName = std::move(newName);
}

// Original deposit method
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance = balance + amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Original withdraw method
void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds. Withdrawal failed." << endl;
    } else {
        balance = balance - amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }
}

// Arithmetic Assignment Operator +=
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Operator +=: Added " << amount << ". New balance: " << balance << endl;
    } else {
        cout << "Operator +=: Invalid amount." << endl;
    }
    return *this;
}

// Arithmetic Assignment Operator -=
BankAccount& BankAccount::operator-=(double amount) {
    if (amount <= 0) {
        cout << "Operator -=: Invalid amount." << endl;
    } else if (amount > balance) {
        cout << "Operator -=: Insufficient funds." << endl;
    } else {
        balance -= amount;
        cout << "Operator -=: Subtracted " << amount << ". New balance: " << balance << endl;
    }
    return *this;
}

// Comparison Operator ==
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

// Comparison Operator <
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

// Comparison Operator >
bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

// Static function to print account details
void BankAccount::printAccount(const BankAccount& account) {
    cout << "=== ACCOUNT DETAILS ===" << endl;
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Account Holder: " << account.accountHolderName << endl;
    cout << "Balance: $" << account.balance << endl;
    cout << "=======================" << endl;
}

// Static function to create account from user input
BankAccount BankAccount::createAccountFromInput() {
    string accNumber, accName;
    double startBalance;

    cout << "Enter account number: ";
    getline(cin, accNumber);

    cout << "Enter account holder name: ";
    getline(cin, accName);

    cout << "Enter initial balance: ";
    while (!(cin >> startBalance) || startBalance < 0) {
        cout << "Invalid amount. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    return {accNumber, accName, startBalance};
}