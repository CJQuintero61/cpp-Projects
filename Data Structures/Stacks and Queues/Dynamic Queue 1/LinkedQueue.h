#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include <cassert> // for assert()
#include "QueueADT.h"
using namespace std;

template <class T>
class LinkedQueue : QueueADT<T>
{
private:
    struct QueueNode
    {
      T info;           // store the info of the node
      QueueNode *next;       // pointer to next node
    };
    QueueNode *front;        // pointer to the front node (first node)
    QueueNode *back;         // pointer to the back node (last node)
    int count;          // counts the number of nodes in the queue
public:
    LinkedQueue();
    ~LinkedQueue();

    bool isEmpty() const;
    bool isFull() const;

    void enqueue(const T &item);   // add an item to the end of the queue
    void dequeue();         // remove the first node from the queue

    T getFront() const;     // returns the front node's info
    T getBack() const;      // returns the back node's info
    int getCount() const;   // returns the number of nodes in the queue

    void clearQueue();              // remove all nodes from the queue
    void printQueue() const;        // print the queue from front to back
};

template <class T>
LinkedQueue<T>::LinkedQueue()
{
    front = nullptr;
    back = nullptr;
    count = 0;
} // end constructor

// the destructor is very similar to clearQueue() and could easily be
// rewritten to call that function, then just give the message
// that the queue was deleted
template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    QueueNode *temp = nullptr;

    // move along the queue deleting the first node each time until
    // there is no more nodes
    while(front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
        count--; // not needed for the destructor but it's here anyways
    }
    // after the loop, front points to nullptr

    back = nullptr; // avoid this dangling pointer

    // this checks that all nodes were deleted and also avoids
    // dangling pointers
    // this makes triple sure that the queue is empty
    if(front == nullptr && back == nullptr && count == 0)
        cout << "Queue deleted.\n";

} // end destructor

template <class T>
bool LinkedQueue<T>::isEmpty() const
{
    // just to make sure the queue is empty, I checked the node count
    // and if front points to something
    return (front == nullptr && count == 0);
} // end isEmpty

template <class T>
bool LinkedQueue<T>::isFull() const
{
    // this function isn't needed for linked queues
    // unless the pc runs out of memory to allocate (I think)
    return false;
} // end isFull

template <class T>
void LinkedQueue<T>::enqueue(const T &item)
{
    QueueNode *newNode = nullptr;   // make a new node
    newNode = new QueueNode;
    newNode->info = item;           // store the item in the new Node's info
    newNode->next = nullptr;        // since the new node goes at the end, its next points to nullptr

    // in an empty queue, make newNode the first node
    if(isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode; // set last node to point to the new last node
        back = newNode;       // update the back node pointer
    }

    count++; // update the count
} // end enqueue

template <class T>
void LinkedQueue<T>::dequeue()
{
    if(isEmpty())
    {
        cout << "Cannot delete from empty queue.\n";
        return;
    }
    else
    {
        QueueNode *temp = nullptr;
        temp = front; // set temp to the front

        front = front->next;
        delete temp;
        count--; // update the count
    }
} // end dequeue

template <class T>
T LinkedQueue<T>::getFront() const
{
    assert(!isEmpty());
    return front->info;
} // end getFront

template  <class T>
T LinkedQueue<T>::getBack() const
{
    assert(!isEmpty());
    return back->info;
} // end getBack

template <class T>
int LinkedQueue<T>::getCount() const
{
    return count;
} // end getCount

template <class T>
void LinkedQueue<T>::clearQueue()
{
    if(isEmpty())
    {
        cout << "The Queue is already empty.\n";
        return;
    }
    else
    {
        QueueNode *temp = nullptr;

        while(front != nullptr)
        {
            temp = front;
            front = front->next;
            delete temp;
            count--;
        }
        front = nullptr;    // avoid dangling pointers
        back = nullptr;     // avoid dangling pointers
    }
} // end clearQueue

// since a queue only works from front to back,
// this is the same as printing a regular linked list
template <class T>
void LinkedQueue<T>::printQueue() const
{
    if(isEmpty())
    {
        cout << "Empty queue.\n";
        return;
    }
    else
    {
        QueueNode *nodePtr = nullptr;
        nodePtr = front; // make a node to traverse list and set it to the front

        cout << "Printing the queue: ";
        while(nodePtr)
        {
            cout << nodePtr->info << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
} // end printQueue




#endif //LINKEDQUEUE_H
