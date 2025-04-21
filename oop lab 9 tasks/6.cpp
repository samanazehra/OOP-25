// Task 2: Create an abstract class Car (model, price).  Include get and set methods from
// these fields. The setPrice Method must be abstract. Create two subclasses Color() and
// Company() from Car and include appropriate setPrice method in these classes. Finally
// write a code that uses Car class and sub classes to display information about instances.
#include <iostream>
#include <vector>
using namespace std;

class Car
{
protected:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}
    virtual ~Car() {}
    void setModel(string m)
    {
        model = m;
    }
    string getModel()
    {
        return model;
    }

    virtual void setPrice(double p) = 0;
    virtual void display() = 0;
    double getPrice()
    {
        return price;
    }
};

class Color : public Car
{
    string finish;

public:
    Color(string m, double p, string f) : Car(m, p), finish(f) {}
    void setPrice(double p)
    {
        price = p;
        if (finish == "Matte")
        {
            price += 20000;
        }
        else if (finish == "Shiny")
        {
            price += 10000;
        }
        else
            price = price;
    }
    void display() 
    {
        cout << "Model: " << model << endl
             << "Price: " << price << endl
             << "Color Finish: " << finish << endl;
    }
};

class Company : public Car
{
    string companyName;

public:
    Company(string m, double p, string c) : Car(m, p), companyName(c) {}
    void setPrice(double p)
    {
        price = p;
        if (companyName == "Honda")
        {
            price += 15000;
        }
        else if (companyName == "Toyota")
        {
            price += 20000;
        }
        else price = price;
    }
    void display() 
    {
        cout << "Company: " << companyName << endl
             << "Model: " << model << endl
             << "Price: " << price << endl;
    }
};

int main()
{
    vector<Car*>cars;
    cars.push_back(new Color("Corolla", 250000, "Matte"));
    cars.push_back(new Company("BRV", 150000, "Honda"));
    cars[0]->setPrice(350000);
    cars[1]->setPrice(300000);
    cout << "Car 1:\n";
    cars[0]->display();
    cout << endl;
    cout << "Car 2:\n";
    cars[1]->display();
    cout << endl;
    for (int i = 0; i < cars.size(); i++)
    delete cars[i];
    return 0;
}