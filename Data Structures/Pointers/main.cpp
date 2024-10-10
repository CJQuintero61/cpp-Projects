/*
 * This code dynamically allocates an array of integers by
 * accepting an integer argument and returns a pointer to the
 * array
 */
#include <iostream>
using namespace std;

int* allocateArray(int);

int main()
{
    int size = 10; // size for the array
    int *ptr = allocateArray(size); // use a pointer to access the array

    // assign values 1 through (size) into the array
    for(int i = 0; i < size; i++)
        ptr[i] = i+1;

    // print the array
    for(int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    cout << endl;

    // change a value in the array
    ptr[3] = 288;

    // print the array
    for(int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    cout << endl;

    delete [] ptr; // delete the allocated array

    return 0;
} // end main

int* allocateArray(int s)
{
    int *arr = nullptr;
    arr = new int[s]; // dynamically allocate an array

    return arr; // return a pointer to the newly made array
} // end allocateArray