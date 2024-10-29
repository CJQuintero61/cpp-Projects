#ifndef QUEUEADT_H
#define QUEUEADT_H

// abstract base class QueueADT has functions that
// all queue classes will use and are derived from.
// All of these will be redefined in each derived class.

template <class T>
class QueueADT
{
public:
    virtual bool isEmpty() const = 0; // returns true if count == 0
    virtual bool isFull() const = 0; // returns true if count == size
    virtual void clearQueue() = 0; // clears the queue
    virtual T getFront() const = 0; // returns the front of the queue
    virtual T getBack() const = 0; // returns the back of the queue
    virtual void enqueue(const T &) = 0; // add an item to the end of the queue
    virtual void dequeue() = 0; // remove the first item of the queue
};

#endif //QUEUEADT_H
