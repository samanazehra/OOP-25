// 2. Write a program that calculates the sum of all the elements in array using pointers
#include<iostream>
using namespace std;
int CalculateSum(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
int main()
{
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<CalculateSum(arr, size);
}

