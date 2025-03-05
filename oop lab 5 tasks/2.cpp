#include <iostream>
#include <vector>

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    Car(string name, int id) : name(name), id(id) {}

    void display() const {
        cout << "Car ID: " << id << ", Name: " << name << endl;
    }
};

class Garage {
private:
    vector<Car*> cars;

public:
    void parkCar(Car* car) {
        cars.push_back(car);
    }

    void listCars() const {
        if (cars.empty()) {
            cout << "Garage is empty.\n";
            return;
        }
        cout << "Cars in garage:\n";
        for (const auto& car : cars) {
            if (car) {
                car->display(); // This may access an invalid object!
            } else {
                cout << "Invalid car reference!\n";
            }
        }
    }
};

int main() {
    Garage garage;
    
    Car car1("Toyota", 101);
    garage.parkCar(&car1);
    
    {
        Car tempCar("Nissan", 102);
        garage.parkCar(&tempCar);
        cout << "Temporary car parked.\n";
    }

    cout << "Listing cars after tempCar is out of scope:\n";
    garage.listCars();

    return 0;
}
