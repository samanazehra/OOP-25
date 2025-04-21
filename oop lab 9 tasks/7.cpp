// Task 3: Write a program to calculate bonus of the employees. The class master derives
// the information from both admin and account classes which intern derives information from
// class person. Create base and all derived classes having same member functions called
// getdata, display data and bonus. Create a base class pointer that capable of accessing
// data of any class and calculates bonus of the specified employee. (Hint: Use virtual
// functions)
#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    string name;
    double salary;
    virtual void getData(string n, double s) = 0;
    virtual void displayData() = 0;
    virtual void bonus() = 0;
    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    string department;

    void getData(string n, double s, string d) {
        name = n;
        salary = s;
        department = d;
    }

    void getData(string n, double s) {
        name = n;
        salary = s;
    }

    void displayData() {
        cout << "Admin\nName: " << name << "\nSalary: " << salary << "\nDepartment: " << department << endl;
    }

    void bonus() {
        cout << "Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
public:
    string section;

    void getData(string n, double s, string sec) {
        name = n;
        salary = s;
        section = sec;
    }

    void getData(string n, double s) {
        name = n;
        salary = s;
    }

    void displayData() {
        cout << "Account\nName: " << name << "\nSalary: " << salary << "\nSection: " << section << endl;
    }

    void bonus() {
        cout << "Bonus: " << salary * 0.08 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData(string n, double s, string d, string sec) {
        name = n;
        salary = s;
        department = d;
        section = sec;
    }

    void getData(string n, double s) {
        name = n;
        salary = s;
    }

    void displayData() {
        cout << "Master\nName: " << name << "\nSalary: " << salary
             << "\nDepartment: " << department << "\nSection: " << section << endl;
    }

    void bonus() {
        cout << "Bonus: " << salary * 0.15 << endl;
    }
};

int main() {
    vector<Person*> employees;
    employees[0].push_back(new Admin);
    employees[0]->getData("Zara", 45000, "IT");
    
    employees[1].push_back(new Account);
    employees[1]->getData("Ahmed", 40000, "Billing");

    employees[2].push_back(new Master);
    employees[2]->getData("Bilal", 60000, "Finance", "Audit");
   
    for (int i = 0; i < employees.size(); i++) {
        employees[i]->displayData();
        employees[i]->bonus();
    }
    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }
    return 0;
}
