#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;
public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { if (balance >= amount) balance -= amount; }
    virtual void applyMonthlyUpdates() {}
    virtual ~BankAccount() {}
    virtual void display() const { cout << accountNumber << " Balance: " << balance << endl; }
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(string accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}
    void applyMonthlyUpdates() override { balance += balance * interestRate; }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(string accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) balance -= amount;
        else cout << "Overdraft limit exceeded for " << accountNumber << endl;
    }
};

class BusinessAccount : public BankAccount {
    double taxRate;
public:
    BusinessAccount(string accNum, double bal, double tax) : BankAccount(accNum, bal), taxRate(tax) {}
    void deposit(double amount) override { balance += amount * (1 - taxRate); }
};

class User {
protected:
    string name;
public:
    User(string n) : name(n) {}
    virtual void performOperation(BankAccount* acc, double amount) = 0;
    virtual ~User() {}
};

class Customer : public User {
public:
    Customer(string n) : User(n) {}
    void performOperation(BankAccount* acc, double amount) override { acc->deposit(amount); }
};

class Employee : public User {
public:
    Employee(string n) : User(n) {}
};

class Teller : public Employee {
public:
    Teller(string n) : Employee(n) {}
    void performOperation(BankAccount* acc, double amount) override { acc->withdraw(amount); }
};

class Manager : public Employee {
public:
    Manager(string n) : Employee(n) {}
    void performOperation(BankAccount* acc, double amount) override { acc->applyMonthlyUpdates(); }
};

int main() {
    vector<BankAccount*> accounts;
    accounts.push_back(new SavingsAccount("1", 1000, 0.02));
    accounts.push_back(new CheckingAccount("2", 500, 200));
    accounts.push_back(new BusinessAccount("3", 2000, 0.1));
    
    vector<User*> users;
    users.push_back(new Customer("Usman"));
    users.push_back(new Teller("Samana"));
    users.push_back(new Manager("Fizza"));
    
    for (auto acc : accounts) acc->display();
    for (auto user : users) user->performOperation(accounts[0], 100);
    for (auto acc : accounts) acc->display();
    
    for (auto acc : accounts) delete acc;
    for (auto user : users) delete user;
}
