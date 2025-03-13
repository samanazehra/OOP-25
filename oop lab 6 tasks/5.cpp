#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}
    virtual void display() = 0;
    virtual ~Vehicles() {}
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;
public:
    Car(double p, int sc, int nd, string ft) : Vehicles(p), seatingCapacity(sc), numberOfDoors(nd), fuelType(ft) {}
};

class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;
public:
    Motorcycle(double p, int nc, int ng, int nw) : Vehicles(p), numberOfCylinders(nc), numberOfGears(ng), numberOfWheels(nw) {}
};

class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int sc, int nd, string ft, string mt) : Car(p, sc, nd, ft), modelType(mt) {}
    void display() override {
        cout << "Price: $" << price << ", Seating Capacity: " << seatingCapacity 
             << ", Number of Doors: " << numberOfDoors << ", Fuel Type: " << fuelType
             << ", Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int nc, int ng, int nw, string mt) : Motorcycle(p, nc, ng, nw), makeType(mt) {}
    void display() override {
        cout << "Price: $" << price << ", Number of Cylinders: " << numberOfCylinders
             << ", Number of Gears: " << numberOfGears << ", Number of Wheels: " << numberOfWheels
             << ", Make Type: " << makeType << endl;
    }
};

int main() {
    Audi audiCar(50000, 5, 4, "Petrol", "A4");
    Yamaha yamahaBike(15000, 2, 6, 2, "YZF-R1");
    
    audiCar.display();
    yamahaBike.display();
    
    return 0;
}
