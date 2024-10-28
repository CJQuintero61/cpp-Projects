#ifndef INTQUEUE_H
#define INTQUEUE_H


class intQueue
{
private:
    int queueSize; // size of the array
    int *queueArray; // the queue array to hold elements
    int front; // hold the front of the queue
    int rear; // hold the rear of the queue
    int count; // number of elements in the queue

public:
    intQueue(int); // constructor

    intQueue(const intQueue &); // copy constructor

    ~intQueue(); // destructor

    // queue operations
    void enqueue(int);   // add an item to the queue
    void dequeue(int &); // remove an item from queue with a catch variable
    bool isEmpty() const;
    bool isFull() const;
    void clear(); // clear the queue
};


#endif INTQUEUE_H
