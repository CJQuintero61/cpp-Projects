// CJ Quintero 11/26/2024
// This program demonstrates a hash table to store and retrieve data
// this is done by using an array of linked lists to add to the linked list
// each time a collision occurs (multiple items with the same hash value (array subscript) )

#include <iostream>
#include "HashArray.h"
using namespace std;

int main()
{
    cout << endl;
    HashArray<int> Hash1;

    cout << "Storing 1-50 in the hash table:\n";
    cout << "Here is the starting hash table:\n";
    // store 1-50 in the hash table
    // obviously 1-50 isn't going to be stored,
    // but it allows a basic demonstration that is fast
    for(int i = 0; i < 50; i++)
        Hash1.store(i + 1);

    Hash1.printHash();
    cout << endl << endl;

    cout << "Trying to add a duplicate value (should fail):\n";
    Hash1.store(37);
    cout << endl;

    cout << "Adding a new value to the hash table:\n";
    Hash1.store(133);
    Hash1.printHash();
    cout << endl;

    cout << "Removing some items from the hash table:\n";
    Hash1.remove(7);
    Hash1.remove(29);
    Hash1.remove(33);
    Hash1.remove(45);
    Hash1.remove(15);
    Hash1.printHash();
    cout << endl;

    cout << "Trying to remove a value not in the hash table (should fail):\n";
    Hash1.remove(15); // 15 was removed already
    cout << endl;

    cout << "Searching for 23:\n";
    if(Hash1.lookUp(23))
        cout << "23 was found in the hash table.\n";
    else
        cout << "23 was not found in the hash table.\n";
    cout << endl;

    cout << "Searching for 99 (should fail):\n";
    if(Hash1.lookUp(99))
        cout << "9 was found in the hash table.\n";
    else
        cout << "99 was not found in the hash table.\n";
    cout << endl;



    cout << endl << endl;
    return 0;
}   // end main

/*
    // This code segment is a demonstration and test of the linked list
    // This is meant to go at the top but will be moved to the bottom in the final
    // code demonstration
    LinkedList<int> List1;

    for(int i = 0; i < 10; i++)
        List1.add((i + 1) * 6);

    cout << "Here is the list:\n";
    List1.print();
    cout << endl << endl;

    cout << "Adding a node (adds 300 to the end):\n";
    List1.add(300);
    List1.print();
    cout << endl << endl;

    cout << "Removing from the front (removes 6):\n";
    List1.remove(6);
    List1.print();
    cout << endl << endl;

    cout << "Removing from the middle (removes 30):\n";
    List1.remove(30);
    List1.print();
    cout << endl << endl;

    cout << "Removing from the end (removes 300):\n";
    List1.remove(300);
    List1.print();
    cout << endl << endl;

    cout << "Searching for a value in the list:\n";
    if(List1.search(42))
        cout << "42 was found in the list.\n";
    else
        cout << "42 was not found in the list.\n";
    cout << endl << endl;

    cout << "Searching for a value not in the list:\n";
    if(List1.search(70))
        cout << "70 was found in the list.\n";
    else
        cout << "70 was not found in the list.\n";

    */