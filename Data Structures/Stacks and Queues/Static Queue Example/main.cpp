#include <iostream>
#include "intQueue.h"
using namespace std;

int main()
{
    intQueue Q1(5); // make a queue

    // queue some values to test
    cout << "Queuing 0\n";
    Q1.enqueue(0);
    cout << "Queuing 1\n";
    Q1.enqueue(1);
    cout << "Queuing 2\n";
    Q1.enqueue(2);
    cout << "Queuing 3\n";
    Q1.enqueue(3);
    cout << "Queuing 4\n";
    Q1.enqueue(4);
    cout << endl;

    // should give the message that queue is full
    cout << "Trying to add to a full queue:\n";
    Q1.enqueue(100);
    cout << endl;

    int catchVar; // to catch the dequeued values

    // how do you spell dequeuing?
    cout << "Dequeuing the values:\n";
    for(int i = 0; i < 5; i++)
    {
        Q1.dequeue(catchVar); // use the catchVar
        cout << "The value dequeued was " << catchVar << endl; // print the value dequeued
    }



    return 0;
} // end main