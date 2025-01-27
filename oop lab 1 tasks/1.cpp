/*1. Write a program that finds the second highest number in a float type array of 20
elements using pointer. */

#include <iostream>
using namespace std;
float FindSecondHighestNumber(float *ptr, int size)
{
    float max = *ptr;
    float secondmax = *ptr;
    for (int i = 0; i < size; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (*(ptr + i) != max && *(ptr + i) > secondmax)
        {
            secondmax = *(ptr + i);
        }
    }
    return secondmax;
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    float arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Second highest number: " << FindSecondHighestNumber(arr, size);
    return 0;
}