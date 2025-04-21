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

class Wallet
{
    double balance;

public:
    Wallet(double b)
    {
        if (b >= 0)
            balance = b;
        else
            cerr << "Balance cannot be negative\n";
    }
    
};
int main() {}