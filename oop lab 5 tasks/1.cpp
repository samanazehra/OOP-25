#include <iostream>

using namespace std;

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {}

    void start() {
        if (!isRunning) {
            isRunning = true;
            cout << "Engine started.\n";
        } else {
            cout << "Engine is already running.\n";
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            cout << "Engine stopped.\n";
        } else {
            cout << "Engine is already off.\n";
        }
    }

    ~Engine() {
        cout << "Engine destroyed.\n";
    }
};

class Car {
private:
    Engine engine;

public:
    Car() {
        cout << "Car created.\n";
    }

    void startCar() {
        cout << "Starting car.\n";
        engine.start();
    }

    void stopCar() {
        cout << "Stopping car.\n";
        engine.stop();
    }

    ~Car() {
        cout << "Car destroyed.\n";
    }
};

int main() {
    cout << "Creating Car object.\n";
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
    return 0;
}
