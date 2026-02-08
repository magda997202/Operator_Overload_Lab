/*
* Name: Magda Hussein
 * Date: 02/07/2026
 * Program: Enhancing the Bank Account Management System
 * Assignment: C++ Lab: Advanced Objects and Classes III
 */
#include "BankAccount.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Clears bad input from the input buffer
void clearInput() {
    cin.clear(); // Reset error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove invalid input
}

// Displays the menu options for the user
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
    vector<BankAccount> accountList; // Stores all bank accounts
    int userChoice; // Stores menu selection

    do {
        showMenu(); // Show menu to user
        cin >> userChoice;

        // Check if user entered invalid input
        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number (1-8)." << endl;
            continue;
        }

        switch(userChoice) {

            // Create a new account
            case 1: {
                clearInput();
                cout << "=== CREATE NEW ACCOUNT (Static Function) ===" << endl;

                // Call static function to create account
                BankAccount newAccount = BankAccount::createAccountFromInput();

                // Add account to list
                accountList.push_back(newAccount);

                cout << "Account created successfully!" << endl;
                break;
            }

            // Display all accounts
            case 2: {
                if (accountList.empty()) {
                    cout << "No accounts found." << endl;
                } else {
                    cout << endl << "*** ALL ACCOUNTS (Static Function) ***" << endl;

                    // Loop through all accounts and print them
                    for (size_t i = 0; i < accountList.size(); i++) {
                        cout << "Account " << (i + 1) << ":" << endl;
                        BankAccount::printAccount(accountList[i]);
                    }
                }
                break;
            }

            // Deposit money into an account
            case 3: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                double depositAmount;

                // Get account number from user
                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                // Get deposit amount
                cout << "Enter deposit amount: ";
                while (!(cin >> depositAmount) || depositAmount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Use overloaded += operator to deposit money
                accountList[accIndex - 1] += depositAmount;
                break;
            }

            // Withdraw money from an account
            case 4: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                double withdrawAmount;

                // Get account number from user
                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                // Get withdrawal amount
                cout << "Enter withdrawal amount: ";
                while (!(cin >> withdrawAmount) || withdrawAmount <= 0) {
                    cout << "Invalid amount. Enter a positive number: ";
                    clearInput();
                }

                // Use overloaded -= operator to withdraw money
                accountList[accIndex - 1] -= withdrawAmount;
                break;
            }

            // Compare two accounts
            case 5: {
                if (accountList.size() < 2) {
                    cout << "Need at least 2 accounts to compare." << endl;
                    break;
                }

                int acc1, acc2;

                // Get account numbers to compare
                cout << "Enter first account number (1-" << accountList.size() << "): ";
                cin >> acc1;
                cout << "Enter second account number (1-" << accountList.size() << "): ";
                cin >> acc2;

                // Check if account numbers are valid
                if (acc1 < 1 || acc1 > static_cast<int>(accountList.size()) ||
                    acc2 < 1 || acc2 > static_cast<int>(accountList.size())) {
                    cout << "Invalid account numbers." << endl;
                    break;
                }

                // Use overloaded comparison operators
                cout << "Comparison Results:" << endl;
                cout << "Accounts have same number? "
                     << (accountList[acc1-1] == accountList[acc2-1] ? "Yes" : "No") << endl;

                cout << "Account " << acc1 << " < Account " << acc2 << "? "
                     << (accountList[acc1-1] < accountList[acc2-1] ? "Yes" : "No") << endl;

                cout << "Account " << acc1 << " > Account " << acc2 << "? "
                     << (accountList[acc1-1] > accountList[acc2-1] ? "Yes" : "No") << endl;

                break;
            }

            // Update account holder name
            case 6: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;
                string newName;

                // Get account number
                cout << "Enter account number (1-" << accountList.size() << "): ";
                while (!(cin >> accIndex) || accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number. Enter (1-" << accountList.size() << "): ";
                    clearInput();
                }

                clearInput();

                // Get new name
                cout << "Enter new account holder name: ";
                getline(cin, newName);

                // Update name using setter function
                accountList[accIndex - 1].setAccountHolderName(newName);

                cout << "Name updated successfully!" << endl;
                break;
            }

            // Test copy constructor and assignment operator
            case 7: {
                if (accountList.empty()) {
                    cout << "No accounts found. Create an account first." << endl;
                    break;
                }

                int accIndex;

                // Get account number to copy
                cout << "Enter account number to copy (1-" << accountList.size() << "): ";
                cin >> accIndex;

                if (accIndex < 1 || accIndex > static_cast<int>(accountList.size())) {
                    cout << "Invalid account number." << endl;
                    break;
                }

                // Copy constructor test
                const BankAccount& copiedAccount(accountList[accIndex - 1]);
                cout << "Copied account using copy constructor:" << endl;
                BankAccount::printAccount(copiedAccount);

                // Assignment operator test
                BankAccount assignedAccount;
                assignedAccount = accountList[accIndex - 1];
                cout << "Assigned account using assignment operator:" << endl;
                BankAccount::printAccount(assignedAccount);

                cout << "Copy tests completed." << endl;
                break;
            }

            // Exit program
            case 8: {
                cout << "Thank you for using Bank Account Management System!" << endl;
                break;
            }

            // Handle invalid menu choices
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
                break;
            }
        }

    } while (userChoice != 8); // Keep running until user chooses Exit

    return 0; // End program
}
