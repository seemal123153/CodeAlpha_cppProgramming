#include <iostream>
#include <string>
using namespace std;

const int MAX_TRANS = 50;

class Account {
private:
    string name;
    int accountNo;
    float balance;

    string transactions[MAX_TRANS];
    int transCount;

public:
    Account(string n, int accNo, float bal) {
        name = n;
        accountNo = accNo;
        balance = bal;
        transCount = 0;
    }

    void addTransaction(string t) {
        if (transCount < MAX_TRANS) {
            transactions[transCount] = t;
            transCount++;
        }
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;

            addTransaction("Deposited: " + to_string(amount));
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;

            addTransaction("Withdrawn: " + to_string(amount));
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void transfer(Account &receiver, float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.balance += amount;

            addTransaction("Transferred: " + to_string(amount) + " to Account " + to_string(receiver.accountNo));
            receiver.addTransaction("Received: " + to_string(amount) + " from Account " + to_string(accountNo));

            cout << "Transfer successful!\n";
        } else {
            cout << "Transfer failed!\n";
        }
    }

    void showInfo() {
        cout << "\n--- Account Info ---\n";
        cout << "Name: " << name << endl;
        cout << "Account No: " << accountNo << endl;
        cout << "Balance: " << balance << endl;
    }

    void showTransactions() {
        cout << "\n--- Transaction History ---\n";

        if (transCount == 0) {
            cout << "No transactions yet.\n";
            return;
        }

        for (int i = 0; i < transCount; i++) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }

    int getAccNo() {
        return accountNo;
    }
};

int main() {

    Account user1("Ali", 101, 5000);
    Account user2("Ahmed", 102, 3000);

    int choice;
    float amount;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Account Info\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            user1.deposit(amount);
            break;

        case 2:
            cout << "Enter withdraw amount: ";
            cin >> amount;
            user1.withdraw(amount);
            break;

        case 3:
            cout << "Enter transfer amount to User2: ";
            cin >> amount;
            user1.transfer(user2, amount);
            break;

        case 4:
            user1.showInfo();
            break;

        case 5:
            user1.showTransactions();
            break;

        case 6:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
