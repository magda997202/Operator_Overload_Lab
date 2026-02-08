//
// Created by User on 2/7/2026.
//


#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructors
    BankAccount();
    BankAccount(std::string number, std::string name, double initialBalance);

    // Rule of Three
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();

    // Accessors
    [[nodiscard]] std::string getAccountNumber() const;
    [[nodiscard]] std::string getAccountHolderName() const;
    [[nodiscard]] double getBalance() const;

    // Mutator
    void setAccountHolderName(std::string newName);

    // Original deposit/withdraw methods
    void deposit(double amount);
    void withdraw(double amount);

    // Arithmetic Assignment Operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // Comparison Operators
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static Utility Functions
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif