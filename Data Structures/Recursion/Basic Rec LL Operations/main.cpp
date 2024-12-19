
#include <iostream>

#include "LinkedList.h"
using namespace std;

int main()
{
    cout << endl; // for readability
    LinkedList<int> List1;

    cout << "Appending 12 random values to List1:\n" << endl;
    List1.appendNode(27);
    List1.appendNode(49);
    List1.appendNode(52);
    List1.appendNode(91);
    List1.appendNode(83);
    List1.appendNode(6);
    List1.appendNode(43);
    List1.appendNode(78);
    List1.appendNode(66);
    List1.appendNode(55);
    List1.appendNode(11);
    List1.appendNode(19);

    cout << "Here is List1:\n";
    List1.print();
    cout << endl;
    cout << "List1 currently has " << List1.getNodeCount() << " nodes.\n";
    cout << endl;

    cout << "Counting the nodes using recursion:\n";
    cout << "List1 currently has " << List1.recGetNodeCount() << " nodes.\n";
    cout << endl;

    cout << "Printing the list in reverse using recursion:\n";
    List1.recPrintReverse();

    return 0;
}   // end main