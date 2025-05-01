#include <any>
#include <exception>
#include <typeinfo>
#include <iostream>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type retrieval";
    }
};

class TypeSafeContainer {
private:
    any data;
public:
    template<typename T>
    void store(const T& value) {
        data = value;
        cout << "Stored value: " << value << endl;  // Debugging print
    }

    template<typename T>
    T get() const {
        cout << "Attempting to retrieve value..." << endl;  // Debugging print
        try {
            return any_cast<T>(data);  // Directly use any_cast
        } catch (const bad_any_cast&) {
            cout << "bad_any_cast caught!" << endl;  // Debugging print
            throw BadTypeException();  // Throw custom exception on type mismatch
        }
    }
};

int main() {
    TypeSafeContainer container;
    container.store<int>(42);

    try {
        cout << "Stored int: " << container.get<int>() << endl;
        cout << "Attempting wrong type: " << container.get<string>() << endl;
    } catch (const BadTypeException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Press Enter to exit..." << endl;
    cin.get();
    return 0;
}
