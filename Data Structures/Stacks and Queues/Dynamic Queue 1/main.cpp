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
    
    return 0;
} // end main
