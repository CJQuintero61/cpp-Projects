/* This program uses pointers to allocate 2 arrays then copies one array
 * to the other in reverse order. Christian Quintero 10/12/2024
 */

#include <iostream>
using namespace std;

int* allocate(); // create an array
void fillArray(int*); // put some values in the first array
void reverseCopy(const int*, int*); // copy the data values in reverse
void print(const int*); // print the array

const int SIZE = 10; // array size

int main()
{
    // make 2 arrays
    int* arr1 = allocate();
    int* arr2 = allocate();

    // put some values in arr1
    fillArray(arr1);

    cout << "Here is array 1:\n";
    print(arr1);
    cout << endl;

    cout << "Reversing the values in a different array:\n";
    reverseCopy(arr1, arr2);
    cout << "Here is array 2:\n";
    print(arr2);

    // free the memory
    delete [] arr1;
    delete [] arr2;

    return 0;
} // end main

int* allocate()
{
    int *ptr = nullptr;
    ptr = new int[SIZE];
    return ptr;
} // end allocate

void fillArray(int *ptr)
{
    for(int i = 0; i < SIZE; i++)
        *(ptr + i) = 10 * (i + 1); // use array notation
} // end fillArray

void reverseCopy(const int *arr1, int *arr2)
{
    int j = SIZE - 1;
    for(int i = 0; i < SIZE; i++)
    {
        *(arr2 + i) = *(arr1 + j);
        j--;
    }
} // end reverseCopy

void print(const int *ptr)
{
    for(int i = 0; i < SIZE; i++)
        cout << *(ptr + i) << " ";
    cout << endl;
} // end print
