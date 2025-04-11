#include <iostream>
#include <string>
using namespace std;

class Account;

class Manager {
public:
    void deposit(Account& acc, double amount);
    void withdraw(Account& acc, double amount);
    void displayAccount(const Account& acc);
};

class Account {
private:
    string accountNumber;
    double balance;
public:
    Account(string accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

void Manager::deposit(Account& acc, double amount) {
    acc.balance += amount;
}

void Manager::withdraw(Account& acc, double amount) {
    if (acc.balance >= amount)
        acc.balance -= amount;
    else
        cout << "Insufficient balance for withdrawal." << endl;
}

void Manager::displayAccount(const Account& acc) {
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Balance: " << acc.balance << endl;
}

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    } else {
        cout << "Transfer failed: Insufficient balance in source account." << endl;
    }
}

int main() {
    Account acc1("123456", 5000);
    Account acc2("654321", 2000);
    Manager mgr;

    cout << "Initial Account States:" << endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    mgr.deposit(acc1, 1000);
    mgr.withdraw(acc2, 500);

    cout << "\nAfter Deposit and Withdrawal:" << endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    transferFunds(acc1, acc2, 2500);

    cout << "\nAfter Fund Transfer:" << endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    return 0;
}
