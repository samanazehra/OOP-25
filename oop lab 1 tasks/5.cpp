/*A movie in a local theater is in great demand. To help a local charity, the theater owner has decided to
donate to the charity a portion of the gross amount generated from the movie. This example designs and
implements a program that prompts the user to input the movie name, adult ticket price, child ticket price,
number of adult tickets sold, number of child tickets sold, and percentage of the gross amount to be
donated to the charity. The output of the program is as follows. Note that the strings, such as "Movie Name:"
, in the first column are left-justified, the numbers in the right column are right-justified, and the
decimal numbers are output with two decimal places. Input: The input to the program consists of the movie
name, adult ticket price, child ticket price, number of adult tickets sold, number of child tickets sold,
and percentage of the gross amount to be donated to the charity. Output: The output is as shown above.*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string moviename;
    float adultticketprice, childticketprice, donationpercent;
    int adulttickets, childtickets;
    cout << "Enter movie name: ";
    getline(cin, moviename);
    cout << "Enter adult ticket price: ";
    cin >> adultticketprice;
    cout << "Enter child ticket price: ";
    cin >> childticketprice;
    cout << "Enter number of adult tickets sold: ";
    cin >> adulttickets;
    cout << "Enter number of child tickets sold: ";
    cin >> childtickets;
    cout << "Enter percentage of gross amount to be donated: ";
    cin >> donationpercent;
    float grossAmount = (adultticketprice * adulttickets) + (childticketprice * childtickets);
    float amountDonated = grossAmount * (donationpercent / 100);
    float netSale = grossAmount - amountDonated;
    cout << fixed << setprecision(2);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << left << setw(30) << "Movie Name:" << moviename << endl;
    cout << left << setw(30) << "Number of Tickets Sold:" << adulttickets + childtickets << endl;
    cout << left << setw(30) << "Gross Amount:" << right << setw(10) << "$ " << grossAmount << endl;
    cout << left << setw(30) << "Percentage of Gross Amount Donated:" << right << setw(10) << donationpercent << " %" << endl;
    cout << left << setw(30) << "Amount Donated:" << right << setw(10) << "$ " << amountDonated << endl;
    cout << left << setw(30) << "Net Sale:" << right << setw(10) << "$ " << netSale << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    return 0;
}
