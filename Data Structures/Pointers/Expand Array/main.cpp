/*
 * This program makes 2 arrays, the initial one, and then one that is twice
 * the size of the first and copies the values to larger one.
 * All empty spots of the new array are to be set to 0.
 * Christian Quintero 10/12/2024
 */

#include <iostream>
using namespace std;

int* allocate(int); // allocate space for the arrays;
void fillArray(int*, int); // put some random values in the array
int* expandArray(const int*, int); // make the expanded array
void print(const int*, int);
// print the array. NOTE: This is specifically meant to print arr2
// and trying to print array 1 will yield random values in the array


int main()
{
    int size = 10;
    int *arr = allocate(size);
    fillArray(arr, size);
    int *arr2 = expandArray(arr, size);

    cout << "Here is the expanded array:\n";
    print(arr2, size);

    // free the memory
    delete [] arr;
    delete [] arr2;

    return 0;
} // end main

int* allocate(int size)
{
    int *ptr = new int[size];
    return ptr;
} // end allocate

void fillArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = 15 * (i+1);
} // end fillArray

int* expandArray(const int *arr1, int size)
{
    int *arr2 = new int[size * 2]; // make an new array twice the size

    for(int i = 0; i < size * 2; i++)
    {
        // because arr1 has [size] elements copy those first elements into array2
        if(i < size)
            arr2[i] = arr1[i];
        else // then fill the rest of the subscripts with 0's
            arr2[i] = 0;
    }
    return arr2;
} // end expandArray

void print(const int *ptr, int size)
{
    for(int i = 0; i < size * 2; i++)
        cout << ptr[i] << " ";
    cout << endl;
} // end print
