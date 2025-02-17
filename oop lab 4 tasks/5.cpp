#include <iostream>
#include <cstdlib>
using namespace std;

class Account {
private:
    float balance;

public:
    Account(float initial_balance) {
        balance = initial_balance;
    }
    void credit(float amount) {
        balance += amount;
    }
    void debit(float amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
        }
    }
    float getBalance() const {
        return balance;
    }
};

int main(int argc, char* argv[]) {
    float initial_balance = atof(argv[1]);
    float credit_amount = atof(argv[2]);
    float debit_amount = atof(argv[3]);
    Account myAccount(initial_balance);
    cout << "Initial balance: " << myAccount.getBalance() << endl;
    myAccount.credit(credit_amount);
    cout << "After credit: " << myAccount.getBalance() << endl;
    myAccount.debit(debit_amount);
    cout << "After debit: " << myAccount.getBalance() << endl;

    return 0;
}
