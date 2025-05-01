#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds!";
    }
};

template <typename T>
class SafeArray {
private:
    T* data;
    size_t size;

public:
    SafeArray(size_t s) : size(s) {
        data = new T[size];
    }

    ~SafeArray() {
        delete[] data;
    }

    size_t getSize() const { return size; }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return data[index];
    }
};

int main() {
    try {
        SafeArray<int> arr(5);

        for (size_t i = 0; i < arr.getSize(); ++i) {
            arr[i] = i * 10;
        }

        cout << "Array contents: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << arr[5] << endl;
    }
    catch (const ArrayIndexOutOfBounds& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
