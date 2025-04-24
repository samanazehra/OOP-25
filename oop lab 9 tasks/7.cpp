#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    string name;
    double salary;

    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual void bonus() = 0;
    virtual ~Person() {}
};

class Admin : virtual public Person {
protected:
    string department;

public:
    void getData() override {
        cout << "Enter Admin Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Department: ";
        cin >> department;
    }

    void displayData() override {
        cout << "Admin\nName: " << name << "\nSalary: " << salary << "\nDepartment: " << department << endl;
    }

    void bonus() override {
        cout << "Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
protected:
    string section;

public:
    void getData() override {
        cout << "Enter Account Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Section: ";
        cin >> section;
    }

    void displayData() override {
        cout << "Account\nName: " << name << "\nSalary: " << salary << "\nSection: " << section << endl;
    }

    void bonus() override {
        cout << "Bonus: " << salary * 0.08 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "Enter Master Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Section: ";
        cin >> section;
    }

    void displayData() override {
        cout << "Master\nName: " << name << "\nSalary: " << salary
             << "\nDepartment: " << department << "\nSection: " << section << endl;
    }

    void bonus() override {
        cout << "Bonus: " << salary * 0.15 << endl;
    }
};

int main() {
    vector<Person*> employees;

    Person* admin = new Admin;
    Person* account = new Account;
    Person* master = new Master;

    employees.push_back(admin);
    employees.push_back(account);
    employees.push_back(master);

    for (int i = 0; i < employees.size(); i++) {
        employees[i]->getData();
    }

    for (int i = 0; i < employees.size(); i++) {
        employees[i]->displayData();
        employees[i]->bonus();
    }

    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    return 0;
}
