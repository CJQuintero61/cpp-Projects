#include <iostream>
#include <fstream>
#include "HashArray.h"
using namespace std;

int main()
{
    ifstream file("data.txt"); // open the file

    if(!file.is_open())
    {
        cout << "file could not be opened.\n";
        return 1;
    }

    HashArray<int> Hash1(5);
    int val;

    // read all data values from the file
    while(file >> val)
        Hash1.store(val);

    Hash1.printHash();  // print the hash table
    file.close();   // close the file

    return 0;
}   // end main