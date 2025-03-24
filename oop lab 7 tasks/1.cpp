#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int n, double b, string name, string type) : accountNumber(n), balance(b), accountHolderName(name), accountType(type) {}
    void deposit(double amount)
    {
        balance += amount;
        cout << "$" << amount << " deposited. New balance: $" << balance << endl;
    }
    double withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "$" << amount << " withdrawn. New balance: $" << balance << endl;
            return amount;
        }
        cout << "Insufficient balance. Available: $" << balance << ". Cannot withdraw $" << amount << ".\n";
        return 0;
    }
    double calculateInterest()
    {
        return 0;
    }
    void printStatement() {}
    void getAccountInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
    }
};

class SavingsAccount : public Account
{
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int n, double b, string name, double r, double mb)
        : Account(n, b, name, "Savings"), interestRate(r), minimumBalance(mb)
    {
        if (balance < minimumBalance)
        {
            cout << "Warning: Balance is below the minimum required of $" << minimumBalance << endl;
        }
    }
    double calculateInterest()
    {
        double interest = balance * (interestRate / 100);
        cout << "Interest earned: $" << interest << endl;
        return interest;
    }
    double withdraw(double amount)
    {
        if ((balance - amount) < minimumBalance)
        {
            cout << "Withdrawal denied. Minimum balance requirement: $" << minimumBalance << endl;
            return 0;
        }
        return Account::withdraw(amount);
    }
};

class CheckingAccount : public Account
{
    double transactionFee;

public:
    CheckingAccount(int n, double b, string name, double fee)
        : Account(n, b, name, "Checking"), transactionFee(fee) {}
    double calculateInterest()
    {
        cout << "Checking accounts do not earn interest.\n";
        return 0;
    }
    double withdraw(double amount)
    {
        double totalAmount = amount + transactionFee;
        if (balance >= totalAmount)
        {
            balance -= totalAmount;
            cout << "$" << amount << " withdrawn with a transaction fee of $" << transactionFee << ". New balance: $" << balance << endl;
            return amount;
        }
        cout << "Insufficient balance. Cannot withdraw $" << amount << " with fee of $" << transactionFee << ".\n";
        return 0;
    }
};

class FixedDepositAccount : public Account
{
    double fixedInterestRate;
    int maturityPeriod;

public:
    FixedDepositAccount(int n, double b, string name, double rate, int period)
        : Account(n, b, name, "Fixed Deposit"), fixedInterestRate(rate), maturityPeriod(period) {}
    double calculateInterest()
    {
        double interest = balance * (fixedInterestRate / 100) * (maturityPeriod / 12.0);
        cout << "Fixed Deposit Interest: $" << interest << endl;
        return interest;
    }
    double withdraw(double amount)
    {
        cout << "Withdrawals are not allowed until maturity period ends (" << maturityPeriod << " months).\n";
        return 0;
    }
};

int main()
{
    SavingsAccount s(12345, 50000, "Samana", 5.0, 30000);
    CheckingAccount c(67890, 20000, "Monis", 15);
    FixedDepositAccount f(11223, 100000, "Usman", 7.5, 24);
    s.getAccountInfo();
    c.getAccountInfo();
    f.getAccountInfo();
    s.deposit(10000);
    s.withdraw(25000);
    s.calculateInterest();
    c.deposit(5000);
    c.withdraw(10000);
    c.calculateInterest();
    f.calculateInterest();
    f.withdraw(50000);
    return 0;
}
