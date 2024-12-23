#include <iostream>
using namespace std;

const int size = 11;


void quickSort(int []);
void recQuickSort(int [], int, int);
int partition(int [], int,  int);
void swap(int &, int &);

int main()
{
    int arr[size];
    arr[0] = 27;
    arr[1] = 13;
    arr[2] = 56;
    arr[3] = 87;
    arr[4] = 99;
    arr[5] = 19;
    arr[6] = 63;
    arr[7] = 78;
    arr[8] = 31;
    arr[9] = 46;
    arr[10] = 33;

    cout << "Here is the array:\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl << endl;

    quickSort(arr);

    cout << "Here is the array after quicksort:\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";




    return 0;
}   // end main

void quickSort(int a[]) // function that calls recQuickSort and only requires the array as a parameter
{
    recQuickSort(a, 0, size - 1);
}   // end quickSort

void recQuickSort(int a[], int first, int last)
{
    int pivot;
    if(first < last)
    {
        pivot = partition(a, first, last); // partition the array into 2 subsets
        recQuickSort(a, first, pivot - 1);  // quicksort the lower subset
        recQuickSort(a, pivot + 1, last);   // quicksort upper subset
    }
}   // end recQuickSort

int partition(int a[], int first, int last)
{
    int pivotIndex, pivotValue, mid;
    mid = (first + last) / 2;
    swap(a[first], a[mid]); // move pivot to the front
    pivotIndex = first;
    pivotValue = a[first];

    for(int i = first + 1; i <= last; i++)
    {
        if(a[i] < pivotValue) // compare the value to the pivot value
        {
            pivotIndex++;
            swap(a[pivotIndex], a[i]);
        }
    }
    swap(a[first], a[pivotIndex]); // move pivot back to the middle
    return pivotIndex;
}   // end partition

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}   // end swap