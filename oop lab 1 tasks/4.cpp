/*4. Write a program that prompts the user to enter the weight of a person in kilograms and outputs the
equivalent weight in pounds. Output both the weights rounded to two decimal places. (Note that 1
kilogram = 2.2 pounds.) Format your output with two decimal places.*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float weightkg, weightpounds;
    cout << "Enter weight in kilograms: ";
    cin >> weightkg;
    weightpounds = weightkg * 2.2;
    cout<<"Weight in kilograms: "<<fixed<<setprecision(2)<<weightkg<<" kg"<<endl;
    cout<<"Weight in pounds: "<<fixed<<setprecision(2)<<weightpounds<<" lbs"<<endl;
}