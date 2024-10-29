/*
 * Working with Queues: In this program, I practiced coding some queues
 * using an abstract base class, and coding my own functions with very little
 * reference to do it on my own mostly. Christian (CJ) Quintero 10/29/2024
 */
#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<string> MyQueue(5);
    Queue<int> AnotherQ(3);
    Queue<int> Cue(3);

    cout << "Queuing [Working]\n";
    MyQueue.enqueue("Working");

    cout << "Queuing [with]\n";
    MyQueue.enqueue("with");

    cout << "Queuing [queues]\n";
    MyQueue.enqueue("queues");

    cout << "Queuing [is]\n";
    MyQueue.enqueue("is");

    cout << "Queuing [fun]\n";
    MyQueue.enqueue("fun!");
    cout << endl << endl;

    cout << "Using a loop to get the front item, then dequeue the item:\n";
    for(int i = 0; i < 5; i++)
    {
        cout << MyQueue.getFront() << " ";
        MyQueue.dequeue();
    }
    cout << endl << endl;

    cout << "Now testing the queue with some values.\n";
    cout << "First let's test isEmpty:\n";
    if(AnotherQ.isEmpty())
        cout << "Object [AnotherQ] is empty.\n";
    else
        cout << "There are items in object [AnotherQ]\n";
    cout << endl << endl;

    cout << "Queuing 5\n";
    AnotherQ.enqueue(5);
    cout << "Queuing 10\n";
    AnotherQ.enqueue(10);
    cout << "Queuing 15\n";
    AnotherQ.enqueue(15);
    cout << endl;

    cout << "Trying to add to a full queue:\n";
    AnotherQ.enqueue(20); // should give a message that queue is full
    cout << endl;

    // should return 15
    cout << "The back item of AnotherQ is " << AnotherQ.getBack() << endl;
    cout << endl;

    cout << "Dequeuing...\n";
    cout << AnotherQ.getFront() << " was dequeued.\n";
    AnotherQ.dequeue();
    cout << AnotherQ.getFront() << " was dequeued.\n";
    AnotherQ.dequeue();
    cout << AnotherQ.getFront() << " was dequeued.\n";
    AnotherQ.dequeue();
    cout << "Trying to deque 1 more time.\n";
    AnotherQ.dequeue();
    cout << endl;

    cout << "Now we will use a 3rd queue object named [Cue].\n";
    cout << "Enqueuing 30\n";
    Cue.enqueue(30);
    cout << "Enqueuing 60\n";
    Cue.enqueue(60);
    cout << "Enqueuing 90\n";
    Cue.enqueue(90);
    cout << endl;

    cout << "Clearing the queue.\n";
    Cue.clearQueue();
    cout << endl;

    cout << "Trying to dequeue after clearing the queue:\n";
    Cue.dequeue();
    cout << endl << endl;

    //  These assertions are in the class functions because they must return something.
    //  In an empty queue, the assertion fails and the program ends

    //  cout << "Testing assert in getFront (This will end the program):\n";
    //  cout << Cue.getFront();

    //  cout << "Testing assert in getBack (This will end the program):\n";
    //  cout << Cue.getBack();

    return 0;
} // end main