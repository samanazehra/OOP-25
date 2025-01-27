/*2. Write a program that calculates the sum of all the elements in array using pointers*/
#include <iostream>
using namespace std;
int CalculateSum(int *ptr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(ptr + i);
    }
    return sum;
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Sum of array: " << CalculateSum(arr, size);
}
