#include "LinkedList.h"
#include <iostream>

using namespace std;

const int SIZE = 20; // this will be the length of the linked list
void binarySequence(char*, int, int, int);


int main()
{
    cout << "*********************************************************************\n";
    cout << "*                           Problem 1                               *\n";
    cout << "*********************************************************************\n";

    LinkedList<int> List1; // make a list

    for(int i = 0; i < SIZE; i++) // add some values to the list
        List1.insertNode((i+1) * 10); // adds multiples of 10 to the list


    // print the list using recursion
    cout << "Here is list 1 printed with recursion:\n";
    List1.recursivePrint(List1.numNodes());
    cout << endl << endl;

    // print in reverse using recursion
    cout << "Here is list 1 printed in reverse with recursion:\n";
    List1.recursiveReversePrint(0);
    cout << endl << endl;

    cout << "Here is list 1 printing every other node:\n";
    List1.recursivePrintEveryOther(List1.numNodes());
    cout << endl << endl;

    cout << "Here is the number of nodes in list 1 using recursion:\n";
    cout << "There are " << List1.recursiveNumNodes(1) << " nodes in list 1.\n";
    cout << endl << endl;

    int x;
    cout << "Enter an integer to search for in list 1.\n";
    cin >> x;
    cout << "Searching for " << x << " in list 1 using recursion:\n";

    if(List1.recursiveSequentialSearch(List1.numNodes(), x))
        cout << x << " was found in list 1.\n";
    else
        cout << x << " was not found in list 1.\n";
    cout << endl << endl;

    cout << "*********************************************************************\n";
    cout << "*                           Problem 2                               *\n";
    cout << "*********************************************************************\n";
    cout << endl << endl;

    int num;
    cout << "Enter an integer:\n";
    cin >> num;
    cout << endl;

    char *arr;
    arr = new char[2 * num + 1];
    arr[2 * num] = '\0'; // store null terminator at the end of the character array

    cout << "Here are all the binary sequences of length " << 2 * num;
    cout << " such that the sum of the first 2\n";
    cout << "bits are equal to the sum of the last 2 bits:\n";
    binarySequence(arr, 0, (2 * num) - 1, 0);
    cout << endl << endl;


    return 0;
} // end main

// finds all sequences of a binary number such that the sum of the
// first 2 bits == sum of the last 2 bits
void binarySequence(char *arr, int start, int end, int difference)
{
    if(difference >= 1 || difference <= -1)
        return;

    // base condition for recursion
    if(start > end)
    {
        if(difference == 0)
            cout << arr << " ";
    }
    else // general case
    {
        // the 2 bits both are 0
        arr[start] = arr[end] = '0';
        binarySequence(arr, start + 1, end - 1, difference);

        // both bits are 1
        arr[start] = arr[end] = '1';
        binarySequence(arr, start + 1, end - 1, difference);

        // first bit is 1, last is 0;
        arr[start] = '1';
        arr[end] = '0';
        binarySequence(arr, start + 1, end - 1, difference - 1);

        // first bit is 0, last is 1;
        arr[start] = '0';
        arr[end] = '1';
        binarySequence(arr, start + 1, end - 1, difference + 1);
    }

} // end binarySequence

