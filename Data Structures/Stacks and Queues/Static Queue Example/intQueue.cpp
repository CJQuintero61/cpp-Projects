#include "intQueue.h"
#include <iostream>
using namespace std;

intQueue::intQueue(int size)
{
    queueSize = size; // set the queue size
    queueArray = new int[size]; // make the array
    front = -1;
    rear = -1;
    count = 0; // start with nothing in queue

    // front and rear are set to -1 because they are invalid subscript values.
    // this avoids confusion when adding elements because front = 0 is a valid
    // array subscript

} // end constructor

intQueue::intQueue(const intQueue &obj)
{
    // avoid self assignment
    if(this != &obj)
    {
        // copy the variables
        queueSize = obj.queueSize;
        queueArray = new int[queueSize]; // make the new array
        front = obj.front;
        rear = obj.rear;
        count = obj.count;

        // copy the elements
        for(int i = 0; i < obj.queueSize; i++)
            queueArray[i] = obj.queueArray[i];
    } // end if
}// end copy constructor

intQueue::~intQueue()
{
    delete [] queueArray;
    queueArray = nullptr; // avoid dangling pointers after deleting

    cout << endl << endl;
    cout << "Queue deleted.\n";
} // end destructor

// add an item to the end of the queue
void intQueue::enqueue(int num)
{
    if(isFull())
    {
        cout << "Cannot add to full queue.\n";
        return;
    }

    // calculate the rear
    rear = (rear + 1) % queueSize;

    // insert the item
    queueArray[rear] = num;

    count++; // update the count

} // end enqueue

// remove an item from the front of the queue
void intQueue::dequeue(int &num)
{
    if(isEmpty())
    {
        cout << "Cannot remove from empty queue.\n";
        return;
    }

    // calculate the front
    front = (front + 1) % queueSize;

    // retrieve the value and store in a catch variable before removing
    num = queueArray[front];

    count--; // update the count
} // end dequeue

// returns true if there are no elements in the queue
bool intQueue::isEmpty() const
{
    return (count == 0);
} // end isEmpty

// returns true if the queue is full
bool intQueue::isFull() const
{
    return (count == queueSize);
} // end isFull

// clears the queue
void intQueue::clear()
{
    front = -1;
    rear = -1;
    count = 0;
} // end clear

