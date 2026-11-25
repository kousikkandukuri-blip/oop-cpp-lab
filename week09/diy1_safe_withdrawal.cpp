#include <iostream>
#include <exception>
#include <string>
using namespace std;

class InsufficientFunds : public exception {
    string msg;
public:
    InsufficientFunds(double bal, double req)
        : msg("Insufficient funds: balance=" + to_string(bal) +
              ", requested=" + to_string(req)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class BankAccount {
private:
    string owner;
    double balance;
public:
    BankAccount(const string &name, double initial)
        : owner(name), balance(initial > 0 ? initial : 0) {}

    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }
    void withdraw(double amt) {
        if (amt <= 0) throw invalid_argument("Withdrawal amount must be positive");
        if (amt > balance) throw InsufficientFunds(balance, amt);
        balance -= amt;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Asha", 1000);
    try {
        acc.withdraw(300);
        cout << "Balance after 300 withdraw: " << acc.getBalance() << endl;
        acc.withdraw(1500);
    } catch (const InsufficientFunds &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
