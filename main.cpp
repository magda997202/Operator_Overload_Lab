/*
* Name: Magda Hussein
 * Date: 02/07/2026
 * Program: Bank Account Management System
 * Assignment: C++ Lab: Objects and Classes I
 */
#include "BankAccount.h"
#include <iostream>
#include <vector>
#include <limits>



using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMenu() {
    cout << endl;
    cout << "=== BANK ACCOUNT MANAGEMENT ===" << endl;
    cout << "1. Create a new account (static function)" << endl;
    cout << "2. Display all accounts (static function)" << endl;
    cout << "3. Deposit money using +=" << endl;
    cout << "4. Withdraw money using -=" << endl;
    cout << "5. Compare accounts (==, <, >)" << endl;
    cout << "6. Update account holder name" << endl;
    cout << "7. Test copy constructor/assignment" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<BankAccount> accountList;
    int userChoice;

    do {
        showMenu();
        cin >> userChoice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number (1-8)." << endl;
            continue;
        }

        switch(userChoice) {
            case 1: {
                clearInput();
                cout << "=== CREATE NEW ACCOUNT (Static Function) ===" << endl;
                BankAccount newAccount = BankAccount::createAccountFromInput();
                accountList.push_back(newAccount);
                cout << "Account created successfully!" << endl;
                break;
            }

            case 2: {
                if (accountList.empty()) {
                    cout << "No accounts found." << endl;
                } else {
                    cout << endl << "*** ALL ACCOUNTS (Static Function) ***" << endl;
                    for (size_t i = 0; i < accountList.size(); i++) {
                        cout << "Account " << (i + 1) << ":" << endl;
                        BankAccount::printAccount(accountList[i]);
                    }
                }
                break;
            }

            case 3: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                double depositAmount;

                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                cout << "Enter deposit amount: ";
                while (!(cin >> depositAmount) || depositAmount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Using overloaded += operator
                accountList[accIndex - 1] += depositAmount;
                break;
            }

            case 4: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                double withdrawAmount;

                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                cout << "Enter withdrawal amount: ";
                while (!(cin >> withdrawAmount) || withdrawAmount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Using overloaded -= operator
                accountList[accIndex - 1] -= withdrawAmount;
                break;
            }

            case 5: {
                if (accountList.size() < 2) {
                    cout << "Need at least 2 accounts to compare." << endl;
                    break;
                }

                int acc1, acc2;
                cout << "Enter first account number (1-" << accountList.size() << "): ";
                cin >> acc1;
                cout << "Enter second account number (1-" << accountList.size() << "): ";
                cin >> acc2;

                if (acc1 < 1 || acc1 > static_cast<int>(accountList.size()) ||
                    acc2 < 1 || acc2 > static_cast<int>(accountList.size())) {
                    cout << "Invalid account numbers." << endl;
                    break;
                }

                // Using overloaded comparison operators
                cout << "Comparison Results:" << endl;
                cout << "Accounts have same number? " << (accountList[acc1-1] == accountList[acc2-1] ? "Yes" : "No") << endl;
                cout << "Account " << acc1 << " < Account " << acc2 << "? " << (accountList[acc1-1] < accountList[acc2-1] ? "Yes" : "No") << endl;
                cout << "Account " << acc1 << " > Account " << acc2 << "? " << (accountList[acc1-1] > accountList[acc2-1] ? "Yes" : "No") << endl;
                break;
            }

            case 6: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                string newName;

                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                clearInput();
                cout << "Enter new account holder name: ";
                getline(cin, newName);

                accountList[accIndex - 1].setAccountHolderName(newName);
                cout << "Name updated successfully!" << endl;
                break;
            }

            case 7: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                cout << "Enter account number to copy (1-" << accountList.size() << "): ";
                cin >> accIndex;

                if (accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number." << endl;
                    break;
                }

                // Test copy constructor
                const BankAccount& copiedAccount(accountList[accIndex - 1]);
                cout << "Copied account using copy constructor:" << endl;
                BankAccount::printAccount(copiedAccount);

                // Test assignment operator
                BankAccount assignedAccount;
                assignedAccount = accountList[accIndex - 1];
                cout << "Assigned account using assignment operator:" << endl;
                BankAccount::printAccount(assignedAccount);

                cout << "Copy tests completed." << endl;
                break;
            }

            case 8: {
                cout << "Thank you for using Bank Account Management System!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
                break;
            }
        }

    } while (userChoice != 8);

    return 0;
}