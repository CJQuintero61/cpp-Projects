/*
 * Christian Quintero : 10/10/2024
 * This program dynamically allocates an array using user
 * input to make the array size. Then, the array is sorted
 * in ascending order, and an average is calculated.
 * Pointer notation is to be used over array notation
 * whenever possible.
 * Validate all input: do not accept negative numbers
 * for test scores or the size of the array
 */
#include <iostream>
#include <iomanip>
using namespace std;

int getSize();
double* allocateArray(int); // return the pointer to the array
void getScores(double* , int); // set the scores of the array
void print(const double*, int); // prints the scores array
void sortArray(double*, int); // sorts array in ascending order using bubble sort algorithm
void swap(double&, double&); // swap 2 elements in the array to sort it
double average(const double*, int); // get an average of the array
void dropLowest(double*, int&); // drop the lowest test score


int main()
{
    int size = getSize(); // get the size of the array and validate the input
    double *scores = allocateArray(size); // returns a pointer to the
    getScores(scores, size); // get input
    double avg = average(scores, size);

    // round output to 2 decimal places; requires <iomanip>
    cout << "Here is the tests and their respective scores:\n";
    cout << setprecision(2) << fixed;
    print(scores, size);
    sortArray(scores, size);
    cout << endl;

    cout << "Here is the sorted scores list:\n";
    print(scores, size);
    cout << "Average: " << avg << endl;
    cout << endl;

    cout << "Here is the sorted array with the lowest grade dropped.\n";
    dropLowest(scores, size);
    print(scores, size);
    avg = average(scores, size); // update the new average
    cout << "Average: " << avg << endl;
    cout << endl;




    delete [] scores; // free the allocated memory array
    return 0;
} // end main

// getSize function: validates user input and returns the size to main
int getSize()
{
    int size; // size of the array

    cout << "Enter the size of the array.\n";
    cin >> size;

    while(size < 1) // validate size
    {
        cin.clear(); // clear the error
        cin.ignore(100,'\n'); // ignore the input buffer

        cout << "Invalid array size entered.\n";
        cout << "The array size must be an integer and at least 1.\n";
        cout << "Enter the size of the array.\n";
        cin >> size;
    }

    return size;
} // end getSize

// allocateArray function: allocate an array and return a pointer to the array
double* allocateArray(int size)
{
    double *arr = nullptr;
    arr = new double[size]; // make an array of doubles


    return arr; // return a pointer to the array
} // end allocateArray

// getScores function: gets input and stores it in the array, also validates input
void getScores(double *arr, int size)
{
    double score;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter the score for test " << i + 1 << ".\n";
        cin >> score;

        while(score < 0 || !cin) // validation loop
        {
            cin.clear(); // clear the error
            cin.ignore(100,'\n'); // ignore the old input
            cout << "Scores must be a positive number. Enter a valid score.\n";
            cin >> score;
        }

        *(arr + i) = score; // use pointer notation to store the score
    }
    cout << endl;
} // end getScores

// print: prints the scores array
void print(const double *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Test " << i+1 << ":\t" << *(arr + i) << endl;
    }

} // end print

//sortArray: sorts the array in ascending order using bubble sort algorithm
void sortArray(double *arr, int size)
{

    // bubble sort algorithm
    for(int maxIndex = size - 1; maxIndex > 0; maxIndex--)
    {
        for(int i = 0; i < maxIndex; i++)
        {
            if(*(arr + i) > *(arr + i + 1))
                swap(*(arr + i), *(arr + i + 1)); // pointer notation whenever possible
        }
    }

} // end sortArray

// swap: swaps 2 elements in the array to sort it
void swap(double &val, double &val2)
{
    double temp = val;
    val = val2;
    val2 = temp;

} // end swap

// average: gets an average of the array
double average(const double *arr, int size)
{
    double total = 0;

    for(int i = 0; i < size; i++)
        total += *(arr + i);

    return total/size;
} // end average

// dropLowest: drops the lowest value
void dropLowest(double *arr, int &size)
{
    double lowest = *(arr); // store the first value as the lowest
    int lowestIndex;

    // find the lowest value in the array
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) < lowest)
        {
            lowest = *(arr + i); // store the new lowest value
            lowestIndex = i;
        }
    }

    // shift each index over by 1 from the lowest grade to remove it
    for(int i = lowestIndex; i < size; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    size--; // reduce the size by 1
} // end dropLowest
