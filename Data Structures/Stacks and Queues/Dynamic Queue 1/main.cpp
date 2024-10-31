#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main()
{
    LinkedQueue<int> Queue1;

    cout << "Making object [Queue1].\n";
    cout << endl << endl;

    cout << "Testing if the queue is empty:\n";
    if(Queue1.isEmpty())
        cout << "The queue is empty.\n";
    else
        cout << "There are items in the queue.\n";
    cout << endl << endl;

    cout << "Enqueuing multiples of lucky number 13:\n";
    for(int i = 0; i < 10; i++)
        Queue1.enqueue((i + 1) * 13); // lucky number 13

    Queue1.printQueue();
    cout << "There are " << Queue1.getCount() << " nodes in Queue1.\n";
    cout << endl;

    cout << "Dequeuing:\n";
    Queue1.dequeue();

    // removes 13 from the queue
    Queue1.printQueue();
    cout << "There are " << Queue1.getCount() << " nodes in Queue1.\n";
    cout << endl;

    cout << "Enqueuing:\n";
    Queue1.enqueue(143); // next multiple of 13!

    Queue1.printQueue();
    cout << "There are " << Queue1.getCount() << " nodes in Queue1.\n";
    cout << endl;

    cout << "The front node's info is " << Queue1.getFront() << endl;
    cout << "The back node's info is " << Queue1.getBack() << endl;
    cout << endl;

    cout << "Clearing the queue...\n";
    Queue1.clearQueue();

    cout << "Testing if the queue is empty:\n";
    if(Queue1.isEmpty())
        cout << "The queue is empty.\n";
    else
        cout << "There are items in the queue.\n";
    cout << endl;

    cout << "Testing [Queue2] with 2 nodes.\n";
    LinkedQueue<int> Queue2;

    Queue2.enqueue(5);
    cout << "Enqueuing 5.\n";
    cout << "The front node's info is " << Queue2.getFront() << endl;
    cout << "The back node's info is " << Queue2.getBack() << endl;
    Queue2.printQueue();
    cout << "There are " << Queue2.getCount() << " nodes in the queue.\n";
    cout << endl;

    cout << "Enqueuing 10.\n";
    Queue2.enqueue(10);
    cout << "The front node's info is " << Queue2.getFront() << endl;
    cout << "The back node's info is " << Queue2.getBack() << endl;
    Queue2.printQueue();
    cout << "There are " << Queue2.getCount() << " nodes in the queue.\n";
    cout << endl;

    cout << "Dequeuing 2 nodes...\n";
    Queue2.dequeue();
    Queue2.dequeue();

    cout << "Testing if the queue is empty:\n";
    if(Queue2.isEmpty())
        cout << "The queue is empty.\n";
    else
        cout << "There are items in the queue.\n";
    cout << endl;
    cout << endl;

    LinkedQueue<int> Queue3;
    cout << "Making [Queue3] with only 1 node.\n";
    cout << endl;

    cout << "Enqueuing 25...\n";
    Queue3.enqueue(25);
    cout << endl;

    cout << "Testing if the queue is empty:\n";
    if(Queue3.isEmpty())
        cout << "The queue is empty.\n";
    else
        cout << "There are items in the queue.\n";
    cout << endl;

    cout << "The front node's info is " << Queue3.getFront() << endl;
    cout << "The back node's info is " << Queue3.getBack() << endl;
    Queue3.printQueue();
    cout << "There are " << Queue3.getCount() << " nodes in the queue.\n";
    cout << endl;



    return 0;
} // end main
