/*6. Write a program that reads a student name followed by five test scores. The program should output the
student’s name, the five test scores, and the average test score. Output the average test score with two
decimal places.*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string firstname;
    string lastname;
    float scores[5];
    float avgscore = 0;
    cin>>firstname>>lastname;
    for (int i = 0; i < 5; i++)
    {
        cin>>scores[i];
    }
    for (int i = 0; i < 5; i++)
    {
        avgscore += scores[i];
    }
    avgscore /= 5;
    cout<<"Student name: "<<firstname<<" "<<lastname<<endl;
    cout<<"Test scores: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<fixed<<setprecision(2)<<scores[i]<<" ";
    }
    cout<<endl;
    cout<<"Average test score: "<<fixed<<setprecision(2)<<avgscore<<endl;
}