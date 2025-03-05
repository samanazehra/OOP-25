#include <iostream>

using namespace std;

class Car {
public:
    mutable int engine_horsepower;
    mutable int seating_capacity;
    mutable int no_of_speakers;

    Car(int hp, int seats, int speakers) : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void changeAttributes(int hp, int seats, int speakers) const {
        engine_horsepower = hp;
        seating_capacity = seats;
        no_of_speakers = speakers;
    }

    void display() const {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
};

int main() {
    Car myCar(150, 5, 6);
    
    cout << "Before modification:\n";
    myCar.display();

    myCar.changeAttributes(200, 4, 8);
    
    cout << "\nAfter modification:\n";
    myCar.display();

    return 0;
}
