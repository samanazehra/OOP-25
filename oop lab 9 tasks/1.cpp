// You have been asked to design a digital wallet application that users can top up, spend
// from, and check their balances. Each user can have only one wallet. The system needs
// to prevent unauthorized or invalid operations (for instance, negative balances or
// exceeding certain transaction limits).
// Tasks:
// 1. Create a Wallet class that:
// o Holds the user’s balance as a private member.
// o Allows only deposit (top-up) and withdrawal (spend) operations through
// public methods.
// o Enforces maximum daily transaction limits (for deposit and withdrawal).
// 2. Create a User class that:
// o Stores minimal user details (like userID, possibly a name, etc.) as private.
// o Has a single Wallet instance hidden from direct manipulation.
// 3. Expose only the methods that the rest of the code needs for normal usage. For
// example, the outside world should not directly manipulate the Wallet’s internal
// details; it should just say user.deposit(...) or user.withdraw(...).
// 4. Ensure the system refuses invalid operations (like overdrawing or exceeding a
// daily limit).
// 5. Demonstrate usage in main() with multiple user objects and different
// deposit/withdraw scenarios.
// Key Points to Consider:
//  How do you design the Wallet class so that internal states (balance, daily limit
// usage) are hidden?
//  How do you structure User to ensure the wallet cannot be manipulated outside
// the intended public interface?
#include <iostream>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

class TransactionLimiter {
public:
    virtual bool canDeposit(double amount, double limit) const = 0;
    virtual bool canWithdraw(double amount, double limit, double balance) const = 0;
    virtual void recordDeposit(double amount) = 0;
    virtual void recordWithdrawal(double amount) = 0;
    virtual void reset() = 0;
    virtual ~TransactionLimiter() {}
};

class DailyLimitTracker : public TransactionLimiter {
private:
    double deposited;
    double withdrawn;

public:
    DailyLimitTracker() : deposited(0), withdrawn(0) {}

    bool canDeposit(double amount, double limit) const override {
        return (deposited + amount <= limit);
    }

    bool canWithdraw(double amount, double limit, double balance) const override {
        return (withdrawn + amount <= limit && amount <= balance);
    }

    void recordDeposit(double amount) override {
        deposited += amount;
    }

    void recordWithdrawal(double amount) override {
        withdrawn += amount;
    }

    void reset() override {
        deposited = 0;
        withdrawn = 0;
    }
};

class Wallet {
private:
    double balance;
    double depositLimit;
    double withdrawLimit;
    TransactionLimiter* tracker;

public:
    Wallet(double depLimit, double witLimit)
        : balance(0), depositLimit(depLimit), withdrawLimit(witLimit), tracker(new DailyLimitTracker()) {}

    ~Wallet() { delete tracker; }

    bool deposit(double amount) {
        if (amount <= 0 || !tracker->canDeposit(amount, depositLimit)) return false;
        balance += amount;
        tracker->recordDeposit(amount);
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || !tracker->canWithdraw(amount, withdrawLimit, balance)) return false;
        balance -= amount;
        tracker->recordWithdrawal(amount);
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetLimits() {
        tracker->reset();
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(const string& uid, const string& uname, double depLimit, double witLimit)
        : userID(uid), name(uname), wallet(depLimit, witLimit) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void displayBalance() const {
        cout << name << "'s Balance: $" << wallet.getBalance() << endl;
    }

    void resetTransactionLimits() {
        wallet.resetLimits();
    }
};

int main() {
    User Samana("001", "Samana", 500.0, 300.0);
    User Usman("002", "Usman", 1000.0, 500.0);

    Samana.deposit(200);
    Samana.withdraw(50);
    Samana.displayBalance();

    Usman.deposit(800);
    Usman.withdraw(400);
    Usman.displayBalance();
    
    Samana.resetTransactionLimits();
    Usman.resetTransactionLimits();

    return 0;
}
