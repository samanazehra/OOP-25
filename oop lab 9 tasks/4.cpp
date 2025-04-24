#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight;

class Passenger {
private:
    string name;
    string id;

public:
    Passenger(const string& n, const string& i) : name(n), id(i) {}

    string getName() const { return name; }
    string getId() const { return id; }

    void requestBooking(Flight& flight);
    void cancelBooking(Flight& flight);
    void upgradeBooking(Flight& flight);
};

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    vector<Passenger*> bookedPassengers;

public:
    Flight(const string& fn, const string& dep, const string& arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap) {}

    string getFlightNumber() const { return flightNumber; }
    string getDeparture() const { return departure; }
    string getArrival() const { return arrival; }

    bool bookSeat(Passenger& passenger) {
        if (bookedPassengers.size() < capacity) {
            bookedPassengers.push_back(&passenger);
            cout << passenger.getName() << " successfully booked on flight " << flightNumber << ".\n";
            return true;
        }
        cout << "No available seats on flight " << flightNumber << " for " << passenger.getName() << ".\n";
        return false;
    }

    bool cancelSeat(Passenger& passenger) {
        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == &passenger) {
                bookedPassengers.erase(it);
                cout << passenger.getName() << " canceled their booking on flight " << flightNumber << ".\n";
                return true;
            }
        }
        cout << "No booking found for " << passenger.getName() << " on flight " << flightNumber << ".\n";
        return false;
    }

    bool upgradeSeat(Passenger& passenger) {
        if (bookedPassengers.size() < capacity) {
            cout << passenger.getName() << " successfully upgraded on flight " << flightNumber << ".\n";
            return true;
        }
        cout << "Upgrade failed: No seats available for " << passenger.getName() << " on flight " << flightNumber << ".\n";
        return false;
    }
};

void Passenger::requestBooking(Flight& flight) {
    if (!flight.bookSeat(*this)) {
        cout << "Booking request failed for " << name << ".\n";
    }
}

void Passenger::cancelBooking(Flight& flight) {
    if (!flight.cancelSeat(*this)) {
        cout << "Cancelation request failed for " << name << ".\n";
    }
}

void Passenger::upgradeBooking(Flight& flight) {
    if (!flight.upgradeSeat(*this)) {
        cout << "Upgrade request failed for " << name << ".\n";
    }
}

int main() {
    Flight flight1("101", "Karachi", "Melbourne", 2);
    Flight flight2("202", "Toronto", "Lahore", 3);

    Passenger p1("Samana Zehra", "47398");
    Passenger p2("Usman Shahid", "58748");
    Passenger p3("Anahita Qasim", "10437");

    p1.requestBooking(flight1);
    p2.requestBooking(flight1);
    p3.requestBooking(flight1);

    p3.requestBooking(flight2);
    p2.requestBooking(flight2);

    p1.cancelBooking(flight1);
    p3.cancelBooking(flight1);

    p2.upgradeBooking(flight2);

    return 0;
}
