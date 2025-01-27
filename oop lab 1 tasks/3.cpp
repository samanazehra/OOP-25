/*3. Write a program in C++ to calculate and print the Electricity bill of a given customer. The customer 
id, name and unit consumed by the user should be taken from the keyboard and display the total amount to
pay to the customer. The charges are as follow: If bill exceeds Rs. 18000 then a surcharge of 15% will 
be charged on top of the bill.*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double oldbill, newbill, charge, surcharge;
    int units;
    string name, customerID;
    cout << "Enter customer ID: ";
    cin >> customerID;
    cin.ignore();
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter units consumed: ";
    cin >> units;
    if (units < 200)
    {
        charge = 16.20;
    }
    else if (units >= 200 && units < 300)
    {
        charge = 20.10;
    }
    else if (units >= 300 && units < 500)
    {
        charge = 27.10;
    }
    else
    {
        charge = 35.90;
    }
    oldbill = units * charge;
    if (oldbill > 18000)
    {
        surcharge = 0.15 * oldbill;
    }
    else
        surcharge = 0;
    newbill = oldbill + surcharge;
    cout << "Customer ID: " << customerID << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Amount Charges @Rs. " << fixed << setprecision(2) << charge << " per unit: " << oldbill << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Payable by the Customer: " << fixed << setprecision(2) << newbill << endl;
}