#include <iostream>
#include <fstream> // to read from data.txt
#include <string>
#include "intHashTable.h"
using namespace std;

int main()
{
    int size = 13;
    intHashTable Hash1(size); // create a hash table object

    ifstream inputFile; // to read from the file only without changing the data
    int num; // value read from the file


    // I had to hardcode the location because I couldn't get the file to open when using
    // inputFile.open("data.txt");
    string fileLocation = "C:\\Users\\cjqui\\CLionProjects\\Data Structures\\Assignments\\Assignment 6\\data.txt";
    inputFile.open(fileLocation); // open the file

    if(!inputFile)
    {
        cout << "File could not be opened.\n";
        return -1;
    }

    // the number of collisions and the locations where the values are supposed to
    // be stored does match my linear probing by hand

    while(inputFile >> num) // read the value and store it in the table
        cout << num << " was added to the table with " << Hash1.add(num) << " collisions.\n";
    cout << endl;

    cout << "Here is Hash1:\n";
    Hash1.print();
    cout << endl << endl;

    while(num != -2)
    {
        cout << "Enter a value to search for or enter -2 to end the loop:";
        cin >> num;
        if(num == -2)
            break;

        if(Hash1.search(num))
            cout << num << " was found in the table.\n";
        else
            cout << num << " was not found in the table.\n";
        cout << endl;
    }



    inputFile.close(); // close the file
    return 0;
} // end main