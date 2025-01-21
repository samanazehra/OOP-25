#include<iostream>
using namespace std;
int main()
{
    double oldbill, newbill, charge, surcharge;
    int units;
    string name, customerID;
    cout<<"Enter customer ID: ";
    cin>>customerID;
    cout<<"Enter customer name: ";
    cin>>name;
    cout<<"Enter units consumed: ";
    cin>>units;
    if (units < 200)
    {
        charge = 16.20;
    }
    else if (units >=200 && units < 300)
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
    else surcharge = 0;
    newbill = oldbill + surcharge;
    cout<<"Customer ID: "<<customerID<<endl;
    cout<<"Customer Name: "<<name<<endl;
    cout<<"Units Consumed: "<<units<<endl;
    cout<<"Amount Charges @Rs. "<<charge<<" per unit: "<<oldbill<<endl;
    cout<<"Surcharge Amount: "<<surcharge<<endl;
    cout<<"Net Amount Payable by the Customer: "<<newbill<<endl;
}
