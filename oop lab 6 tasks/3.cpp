#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder(const string& order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(const string& order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder(const string& order) override { cout << name << " took order: " << order << endl; }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}
    void prepareOrder(const string& order) override { cout << name << " is preparing: " << order << endl; }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}
    void generateBill(double amount) override { cout << name << " generated a bill of: $" << amount << endl; }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder(const string& order) override { cout << name << " (Manager) took order: " << order << endl; }
    void generateBill(double amount) override { cout << name << " (Manager) generated a bill of: $" << amount << endl; }
};

class Menu {
protected:
    vector<string> items;
public:
    virtual double calculateTotal() = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu() { items = {"Burger", "Pasta", "Salad"}; }
    double calculateTotal() override { return items.size() * 10.0; }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu() { items = {"Tea", "Coffee", "Juice"}; }
    double calculateTotal() override { return items.size() * 5.0 * 1.1; }
};

int main() {
    vector<Employee*> employees;
    employees.push_back(new Waiter(1, "Samana"));
    employees.push_back(new Chef(2, "Fizza"));
    employees.push_back(new Cashier(3, "Batool"));
    employees.push_back(new Manager(4, "Usman"));
    
    FoodMenu foodMenu;
    BeverageMenu beverageMenu;
    
    for (auto emp : employees) {
        if (IOrderTaker* taker = dynamic_cast<IOrderTaker*>(emp))
            taker->takeOrder("Pasta");
        if (IBiller* biller = dynamic_cast<IBiller*>(emp))
            biller->generateBill(foodMenu.calculateTotal());
    }
    
    for (auto emp : employees) delete emp;
}