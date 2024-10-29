#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "QueueADT.h"
#include <cassert>
using namespace std;

template <class T>
class Queue : public QueueADT<T>
{
private:
    int size;   // max size of the queue
    int front;  // holds the first queue item
    int back;   // holds the last queue item
    int count;   // count the number of items in queue
    T *list;    // pointer to the array

public:
    Queue();        // default constructor
    Queue(int);     // parameterized constructor
    ~Queue();       // deconstructor

    // basic operations
    bool isEmpty() const;           // True if count == 0
    bool isFull() const;            // True if count == size;
    void enqueue(const T &);        // add an item to the end of the queue
    void dequeue();                 // remove an item from the front of the queue
    T getFront() const;             // returns the front of the queue
    T getBack() const;              // returns the back of the queue
    void clearQueue();              // clears the queue


};

template <class T>
Queue<T>::Queue()
{
    size = 5; // this is a simple program to practice. No need for a large default size
    front = 0;
    back = size - 1;
    count = 0;
    list = new T[size]; // our array
} // end default constructor

template <class T>
Queue<T>::Queue(int s)
{
    size = s; // user inputs size
    front = 0;
    back = size - 1;
    count = 0;
    list = new T[size];
} // end parameterized constructor

template <class T>
Queue<T>::~Queue()
{
    delete [] list;         // free the memory
    list = nullptr;         // avoid dangling pointers
    cout << "Queue deleted.\n";
} // end destructor

template <class T>
bool Queue<T>::isEmpty() const
{
    return (count == 0);
} // end isEmpty

template <class T>
bool Queue<T>::isFull() const
{
    return (count == size);
} // end isFull

template <class T>
void Queue<T>::enqueue(const T &obj)
{
    // must be checked first
    if(isFull())
    {
        cout << "Cannot add to full queue.\n";
        return;
    }

    back = (back + 1) % size;   // algorithm to update back variable
    list[back] = obj;           // store the item
    count++;                    // increment count
} // end enqueue

template <class T>
void Queue<T>::dequeue()
{
    // must be checked first
    if(isEmpty())
    {
        cout << "Cannot remove from empty queue.\n";
        return;
    }

    front = (front + 1) % size;     // algorithm to update front
    count--;                        // decrement count
} // end dequeue

template <class T>
T Queue<T>::getFront() const
{
    // if the queue IS empty, end the program, otherwise return the front
    assert(!isEmpty());
    return list[front];
} // end getFront

template <class T>
T Queue<T>::getBack() const
{
    // uf the queue IS empty, end the program, otherwise return the back
    assert(!isEmpty());
    return list[back];
} // end getBack

template <class T>
void Queue<T>::clearQueue()
{
    count = 0;
    front = 0;
    back = size - 1;
} // end clearQueue







#endif //QUEUE_H
