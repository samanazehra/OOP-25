#include <iostream>
#include <string>
using namespace std;
class Date
{
    int day;
    int month;
    int year;

public:
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main(int argc, char *argv[])
{
    Date DateTest;
    DateTest.setDay(stoi(argv[1]));
    DateTest.setMonth(stoi(argv[2]));
    DateTest.setYear(stoi(argv[3]));
    DateTest.displayDate();
    return 0;
}
