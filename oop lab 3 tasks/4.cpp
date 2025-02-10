// Create a class called Employee that includes three pieces of information as instance variables—a first name (type
// String), a last name (type String) and a monthly salary (double). If the monthly salary is not positive, set it to 0.0.
// Write a test application named EmployeeTest that demonstrates class Employee’s capabilities. Create two
// Employee objects and display each object’s yearly salary. Then give each Employee a 10% raise and display each
// Employee’s yearly salary again.

#include <iostream>
#include <string>
using namespace std;

class Employee
{
    string firstName;
    string lastName;
    double monthlySalary;

public:
    void setFirstName(string f)
    {
        firstName = f;
    }
    string getFirstName()
    {
        return firstName;
    }
    void setLastName(string l)
    {
        lastName = l;
    }
    string getLastName()
    {
        return lastName;
    }
    void setMonthlySalary(double s)
    {
        if (s < 0)
        {
            monthlySalary = 0.0;
        }
        else monthlySalary = s;
    }
    double getMonthlySalary()
    {
        return monthlySalary;
    }
};

int main(int argc, char*argv[])
{
    Employee emp1, emp2;
    emp1.setFirstName(argv[1]);
    emp1.setLastName(argv[2]);
    emp1.setMonthlySalary(stod(argv[3]));
    emp2.setFirstName(argv[4]);
    emp2.setLastName(argv[5]);
    emp2.setMonthlySalary(stod(argv[6]));
    cout << emp1.getFirstName() << " " << emp1.getLastName() << "'s yearly salary before raise: $" << emp1.getMonthlySalary() * 12 << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName() << "'s yearly salary before raise: $" << emp2.getMonthlySalary() * 12 << endl;
    cout << emp1.getFirstName() << " " << emp1.getLastName() << "'s yearly salary after raise: $" << emp1.getMonthlySalary() * 1.1 * 12 << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName() << "'s yearly salary after raise: $" << emp2.getMonthlySalary() * 1.1 * 12 << endl;
    return 0;
}