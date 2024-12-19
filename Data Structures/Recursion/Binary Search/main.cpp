#include <iostream>
using namespace std;


int recBinarySearch(int [], int, int, int); // uses recursion to perform binary search

int main()
{
    int size = 15;
    int arr[size];
    int num;

    for(int i = 0; i < size; i++)
        arr[i] = (i + 1) * 4;

    cout << "Here is the array:\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Enter a number to search for in the array:\n";
    cin >> num;

    int loc = recBinarySearch(arr, 0, size - 1, num);

    if(loc != -1)
        cout << num << " was found at subscript " << loc << endl;
    else
        cout << num << " was not found in the array.\n";


    return 0;
}   // end main

int recBinarySearch(int arr[], int first, int last, int val)
{
    if(first > last)
        return -1; // not found in array

    int mid = (first + last) / 2;

    // if the middle value is the one we want return it
    if(arr[mid] == val)
        return mid;
    else if(val < arr[mid]) // if val < [mid], make last == mid - 1
        return recBinarySearch(arr, first, mid - 1, val);
    else if(val > arr[mid]) // if val > [mid], make first == mid + 1
        return recBinarySearch(arr, mid + 1, last, val);

}   // end recBinarySearch