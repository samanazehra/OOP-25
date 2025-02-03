#include <iostream>
#include <cstdlib>
using namespace std;

void* addToArray(void* arr, int size, int sum) {
    int* intArr = (int*)arr;
    for (int i = 0; i < size; i++) {
        intArr[i] += sum;
    }
    return arr;
}

int main(int argc, char* argv[]) {
    int size = argc - 1;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    addToArray(arr, size, 10);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}