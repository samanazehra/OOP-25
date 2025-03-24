#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
    {
        amount = amt;
        currencyCode = code;
        currencySymbol = symbol;
        exchangeRate = rate;
    }

    virtual double convertToBase() const
    {
        return amount * exchangeRate;
    }

    virtual void displayCurrency() const
    {
        cout << fixed << setprecision(2) << currencySymbol << " " << amount << " (" << currencyCode << ")\n";
    }

    virtual double convertTo(const Currency &targetCurrency) const
    {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() const override
    {
        cout << "$" << fixed << setprecision(2) << amount << " (USD)\n";
    }
};

class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "E ", 1.1) {}

    void displayCurrency() const override
    {
        cout << "E " << fixed << setprecision(2) << amount << " (EUR)\n";
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs. ", 0.006) {}

    void displayCurrency() const override
    {
        cout << "Rs. " << fixed << setprecision(2) << amount << " (PKR)\n";
    }
};

int main()
{
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();
    cout << "\nConversions:\n";
    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR\n";
    cout << "50 EUR to USD: " << eur.convertTo(usd) << " USD\n";
    cout << "5000 PKR to USD: " << pkr.convertTo(usd) << " USD\n";

    return 0;
}
