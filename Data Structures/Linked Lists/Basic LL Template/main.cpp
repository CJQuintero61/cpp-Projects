// a Linked List demonstration with some basic functions
// I made this because I realized I didn't have a LL template file that I could
// use when trying to practice other things, so the .h file in this directory will
// be reused
// CJ Quintero 12/16/2024
#include <iostream>

#include "LinkedList.h"
using namespace std;

int main()
{
    cout << endl; // for readability
    LinkedList<int> List1;

    // append multiples of 5 to the list
    for(int i = 0; i < 10; i++)
        List1.appendNode( (i + 1) * 5);

    cout << "Here is List1:\n";
    List1.print();
    cout << endl;
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    cout << "Inserting values to the front, middle, and end of List1:\n";
    List1.insertNode(100, 0);
    List1.insertNode(200, 5);
    List1.insertNode(300, 30);

    cout << "Here is List1:\n";
    List1.print();
    cout << endl;
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    cout << "Deleting nodes from the front, middle, and end of List1:\n";
    List1.deleteNode(100);
    List1.deleteNode(200);
    List1.deleteNode(300);

    cout << "Here is List1:\n";
    List1.print();
    cout << endl;
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    // as we can see, the node count is unchanged, and we get the error message
    cout << "Trying to APPEND a duplicate value to the list (should fail):\n";
    List1.appendNode(35);
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    // as we can see, the node count is unchanged, and we get the error message
    cout << "Trying to INSERT a duplicate value to the list (should fail):\n";
    List1.insertNode(5, 7);
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    cout << "Trying to delete a value not in the list (should fail):\n";
    List1.deleteNode(47);
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    cout << "Here is List1:\n";
    List1.print();
    cout << endl;
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    cout << "Clearing the list:\n";
    List1.clearList();
    cout << endl;

    cout << "Trying to print the empty list:\n";
    List1.print();
    cout << endl;
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;

    cout << "Appending to List1:\n";
    for(int i = 0; i < 10; i++)
        List1.appendNode( (i + 1) * 9);

    cout << "Here is List1:\n";
    List1.print();
    cout << endl;
    cout << "There are currently " << List1.getNodeCount() << " nodes in List1.\n";
    cout << endl;




    return 0;
}   // end main