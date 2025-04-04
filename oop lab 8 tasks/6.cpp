#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    float monthlyIncome;

public:
    void getData() {
        Person::getData();
        cout << "Enter Admin Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    float bonus() {
        return monthlyIncome * 0.05 * 12;
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }
};

class Accounts : public Person {
private:
    string name;
    float monthlyIncome;

public:
    void getData() {
        Person::getData();
        cout << "Enter Accounts Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    float bonus() {
        return monthlyIncome * 0.05 * 12;
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }
};

int main() {
    Admin adminEmployee;
    Accounts accountsEmployee;

    cout << "--- Enter Admin Employee Info ---" << endl;
    adminEmployee.getData();

    cout << "\n--- Enter Accounts Employee Info ---" << endl;
    accountsEmployee.getData();

    cout << "\n--- Admin Employee Info ---" << endl;
    adminEmployee.displayData();

    cout << "\n--- Accounts Employee Info ---" << endl;
    accountsEmployee.displayData();

    return 0;
}
