#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
    string accountHolder;
    double balance;

    BankAccount(string holder) : accountHolder(holder), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". Current Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". Current Balance: $" << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    cout << "Welcome to the Banking System!" << endl;

    string accountHolder;
    cout << "Enter account holder's name: ";
    getline(cin, accountHolder);

    BankAccount account(accountHolder);

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice (1-4): ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                double depositAmount;
                cout << "Enter the deposit amount: $";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 2: {
                double withdrawalAmount;
                cout << "Enter the withdrawal amount: $";
                cin >> withdrawalAmount;
                account.withdraw(withdrawalAmount);
                break;
            }
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Thank you for using the Banking System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}
