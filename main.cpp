/*
* Name: Magda Hussein
 * Date: 01/30/2026
 * Program: Bank Account Management System
 * Assignment: C++ Lab: Objects and Classes I
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class BankAccount {
private:
    string accountNumber;        // The account number
    string accountHolderName;    // The name of the account holder
    double balance;              // The current balance

public:
    // Default constructor
    BankAccount() {
        accountNumber = "";
        accountHolderName = "";
        balance = 0.0;
    }

    // Parameterized constructor for initial state
    BankAccount(string number, string name, double initialBalance) {
        accountNumber = number;
        accountHolderName = name;
        balance = initialBalance;
    }

    // Accessor (getter) methods for all member variables
    string getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }

    double getBalance() {
        return balance;
    }

    // Mutator (setter) method for accountHolderName
    void setAccountHolderName(string newName) {
        accountHolderName = newName;
    }

    // Member function for deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Member function for withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance = balance - amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }
};

// Helper function to clear input errors
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function to display the menu
void showMenu() {
    cout << endl;
    cout << "=== BANK ACCOUNT MANAGEMENT ===" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Display all accounts" << endl;
    cout << "3. Deposit money" << endl;
    cout << "4. Withdraw money" << endl;
    cout << "5. Update account holder name" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Managing a collection of accounts using a std::vector
    vector<BankAccount> accountList;
    int userChoice;

    do {
        showMenu();
        cin >> userChoice;

        // Handle invalid menu choices
        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number (1-6)." << endl;
            continue;
        }

        switch(userChoice) {
            case 1: {
                // Create a new account
                string accNumber, accName;
                double startBalance;

                clearInput();  // Clear the input buffer

                cout << "Enter account number: ";
                getline(cin, accNumber);

                cout << "Enter account holder name: ";
                getline(cin, accName);

                cout << "Enter initial balance: ";
                while (!(cin >> startBalance) || startBalance < 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Create account using parameterized constructor
                BankAccount newAccount(accNumber, accName, startBalance);
                accountList.push_back(newAccount);

                cout << "Account created successfully!" << endl;
                break;
            }

            case 2: {
                // Display all accounts
                if (accountList.empty()) {
                    cout << "No accounts found." << endl;
                } else {
                    cout << endl << "*** ALL ACCOUNTS ***" << endl;
                    for (size_t i = 0; i < accountList.size(); i++) {
                        cout << "Account " << (i + 1) << ":" << endl;
                        cout << "  Number: " << accountList[i].getAccountNumber() << endl;
                        cout << "  Name: " << accountList[i].getAccountHolderName() << endl;
                        cout << "  Balance: " << accountList[i].getBalance() << endl;
                        cout << endl;
                    }
                }
                break;
            }

            case 3: {
                // Deposit money
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                double depositAmount;

                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > (int)accountList.size()) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                cout << "Enter deposit amount: ";
                while (!(cin >> depositAmount) || depositAmount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Include robust input validation
                accountList[accIndex - 1].deposit(depositAmount);
                break;
            }

            case 4: {
                // Withdraw money
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                double withdrawAmount;

                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > (int)accountList.size()) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                cout << "Enter withdrawal amount: ";
                while (!(cin >> withdrawAmount) || withdrawAmount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Think about how to handle insufficient funds
                accountList[accIndex - 1].withdraw(withdrawAmount);
                break;
            }

            case 5: {
                // Update account holder name
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                string newName;

                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > (int)accountList.size()) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                clearInput();  // Clear the input buffer
                cout << "Enter new account holder name: ";
                getline(cin, newName);

                // Use the mutator (setter) method
                accountList[accIndex - 1].setAccountHolderName(newName);
                cout << "Name updated successfully!" << endl;
                break;
            }

            case 6: {
                cout << "Thank you for using Bank Account Management System!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
            }
        }

    } while (userChoice != 6);

    return 0;
}