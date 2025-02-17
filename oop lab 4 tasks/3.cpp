#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    size_t arraySize;

public:
    DynamicArray() : arr(nullptr), arraySize(0) {}

    DynamicArray(int n) : arraySize(n) {
        arr = new int[arraySize]();
    }

    DynamicArray(const DynamicArray& other) : arraySize(other.arraySize) {
        arr = new int[arraySize];
        for (size_t i = 0; i < arraySize; ++i) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), arraySize(other.arraySize) {
        other.arr = nullptr;
        other.arraySize = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;
            arraySize = other.arraySize;
            arr = new int[arraySize];
            for (size_t i = 0; i < arraySize; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            arraySize = other.arraySize;
            other.arr = nullptr;
            other.arraySize = 0;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    size_t size() const {
        return arraySize;
    }

    int& at(int index) {
        return arr[index];
    }

    const int& at(int index) const {
        return arr[index];
    }

    void resize(int newSize) {
        if (newSize <= 0) {
            delete[] arr;
            arr = nullptr;
            arraySize = 0;
        } else {
            int* newArr = new int[newSize]();
            for (size_t i = 0; i < (arraySize < (size_t)newSize ? arraySize : (size_t)newSize); ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            arraySize = newSize;
        }
    }
};

int main(int argc, char* argv[]) {
    DynamicArray arr1(5);
    for (int i = 0; i < arr1.size(); ++i) {
        arr1.at(i) = i + 1;
    }

    DynamicArray arr2 = arr1;
    DynamicArray arr3(3);
    arr3 = arr1;

    cout << "arr1: ";
    for (size_t i = 0; i < arr1.size(); ++i) {
        cout << arr1.at(i) << " ";
    }
    cout << endl;

    cout << "arr2 (after copy): ";
    for (size_t i = 0; i < arr2.size(); ++i) {
        cout << arr2.at(i) << " ";
    }
    cout << endl;

    cout << "arr3 (after copy assignment): ";
    for (size_t i = 0; i < arr3.size(); ++i) {
        cout << arr3.at(i) << " ";
    }
    cout << endl;

    DynamicArray arr4 = move(arr1);
    DynamicArray arr5(3);
    arr5 = move(arr2);

    cout << "arr1 (after move): ";
    for (size_t i = 0; i < arr1.size(); ++i) {
        cout << arr1.at(i) << " ";
    }
    cout << endl;

    cout << "arr4 (after move): ";
    for (size_t i = 0; i < arr4.size(); ++i) {
        cout << arr4.at(i) << " ";
    }
    cout << endl;

    cout << "arr2 (after move assignment): ";
    for (size_t i = 0; i < arr2.size(); ++i) {
        cout << arr2.at(i) << " ";
    }
    cout << endl;

    arr4.resize(8);
    cout << "arr4 after resize: ";
    for (size_t i = 0; i < arr4.size(); ++i) {
        cout << arr4.at(i) << " ";
    }
    cout << endl;

    return 0;
}
