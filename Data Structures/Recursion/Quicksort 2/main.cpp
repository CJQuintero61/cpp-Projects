#include <iostream>
#include "ArrayList.h"
using namespace std;

int main()
{
    cout << endl;

    ArrayList<int> List1;
    int count, size;

    cout << "Adding 10 random values to the list.\n";
    List1.add(13);
    List1.add(27);
    List1.add(42);
    List1.add(19);
    List1.add(40);
    List1.add(24);
    List1.add(89);
    List1.add(20);
    List1.add(11);
    List1.add(81);
    cout << endl;

    cout << "Here is the list:\n";
    List1.print();
    cout << endl << endl;

    cout << "Sorting the array:\n";
    List1.quicksort();
    cout << "Here is the list:\n";
    List1.print();
    cout << endl << endl;
    cout << "40 is at " << List1.binarySearch(40) << endl;




    return 0;
}   // end main