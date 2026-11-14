#include <iostream>
#include <string>
using namespace std;

struct Transaction {
    string type;
    long long amount;
    long long balanceAfter;
};

class SavingsAccount {
private:
    string accountNumber;
    long long balance;
    Transaction transactions[10];
    int transactionCount;
    int nextIndex;

    void recordTransaction(string type, long long amount) {
        transactions[nextIndex] = {type, amount, balance};
        nextIndex = (nextIndex + 1) % 10;

        if (transactionCount < 10) {
            transactionCount++;
        }
    }

public:
    SavingsAccount(string number, long long initialBalance) {
        accountNumber = number;
        balance = initialBalance;
        transactionCount = 0;
        nextIndex = 0;
    }

    long long getBalance() const {
        return balance;
    }

    void deposit(long long amount);
    void withdraw(long long amount);
    void miniStatement();
};

void SavingsAccount::deposit(long long amount) {
    if (amount <= 0) {
        cout << "Invalid deposit amount." << endl;
        return;
    }

    balance += amount;
    recordTransaction("Deposit", amount);
    cout << "Deposited: Rs. " << amount << endl;
}

void SavingsAccount::withdraw(long long amount) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
        return;
    }

    if (amount > balance) {
        cout << "Insufficient balance." << endl;
        return;
    }

    balance -= amount;
    recordTransaction("Withdrawal", amount);
    cout << "Withdrawn: Rs. " << amount << endl;
}

void SavingsAccount::miniStatement() {
    cout << "\n========== MINI STATEMENT ==========" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: Rs. " << balance << endl;
    cout << "\nTransaction History (Last 10)" << endl;

    int startIndex;

    if (transactionCount == 10) {
        startIndex = nextIndex;
    } else {
        startIndex = 0;
    }

    for (int i = 0; i < transactionCount; i++) {
        int index = (startIndex + i) % 10;

        cout << i + 1 << ". "
             << transactions[index].type
             << " - Rs. " << transactions[index].amount
             << " | Balance: Rs. "
             << transactions[index].balanceAfter << endl;
    }

    cout << "====================================" << endl;
}

int main() {
    SavingsAccount account("SAV1001", 5000);

    cout << "SAVINGS ACCOUNT TRANSACTION SYSTEM" << endl;
    cout << "Initial Balance: Rs. " << account.getBalance() << endl;

    account.deposit(500);
    account.deposit(300);
    account.withdraw(200);
    account.deposit(1000);
    account.withdraw(400);
    account.deposit(250);
    account.withdraw(150);
    account.deposit(700);
    account.withdraw(300);
    account.deposit(450);
    account.withdraw(100);

    account.miniStatement();

    return 0;
}