#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    int initialSize = 5; 
    int* array = new int[initialSize]; 
    int count = 0; 

    for (int i = 1; i < argc; ++i) {
        if (count >= 2 * initialSize) { 
            initialSize *= 2;
            int* newArray = new int[initialSize];
            for (int j = 0; j < count; ++j) newArray[j] = array[j]; // 
            delete[] array; 
            array = newArray; 
        }
        array[count++] = atoi(argv[i]); 
    }

    if (count < initialSize) {
        int* newArray = new int[count];
        for (int i = 0; i < count; ++i) newArray[i] = array[i]; 
        delete[] array;
        array = newArray;
    }

    cout << "Final array (" << count << " elements): ";
    for (int i = 0; i < count; ++i) cout << array[i] << " ";
    cout << endl;

    delete[] array;
    return 0;
}