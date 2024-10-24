#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
#include <string> // in case a string stack is made
using namespace std;



template <class T>
class DynStack
{
private:
    struct stackNode
    {
        T info;
        stackNode *next;
    };
    stackNode *top; // pointer to top

public:
    DynStack(); // constructor
    ~DynStack(); // destructor

    void push(T); // push a value onto the stack
    void pop(T&); // copy the removed value into a catch variable
    void getTop(T&); // returns the top nodes info without removing it
    bool isEmpty() const; // returns true if there are no nodes in the stack
    void print() const; // print the stack
};

template <class T>
DynStack<T>::DynStack()
{
    top = nullptr;
} // end constructor

template <class T>
DynStack<T>::~DynStack()
{
    stackNode *nodePtr = nullptr;
    nodePtr = top; // position nodePtr to the top

    while(nodePtr != nullptr)
    {
        top = nodePtr->next;
        delete nodePtr;
        nodePtr = top;
    }

    if(top == nullptr)
        cout << "Stack deleted.\n";
} // end destructor

template <class T>
void DynStack<T>::push(T item)
{
    stackNode *newNode = nullptr;
    newNode = new stackNode;
    newNode->info = item;

    if(isEmpty()) // if empty make it the first node in the stack
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else // else add the new node after top
    {
        newNode->next = top;
        top = newNode;
    }
} // end push

template <class T>
void DynStack<T>::pop(T &item)
{
    item = top->info; // store the top item in a catch variable

    if(isEmpty())
    {
        cout << "Cannot remove from an empty list.\n";
        return;
    }
    else
    {
        stackNode *nodePtr = nullptr;
        nodePtr = top;
        top = top->next;
        delete nodePtr;
    }
} // end pop

template <class T>
void DynStack<T>::getTop(T &item)
{
    item = top->info;
} // end getTop

template <class T>
bool DynStack<T>::isEmpty() const
{
    return (top == nullptr);
} // end isEmpty

template <class T>
void DynStack<T>::print() const
{
    cout << "Printing the stack:\n";
    if(isEmpty())
    {
        cout << "Empty list.\n";
        return;
    }

    stackNode *nodePtr = nullptr;
    nodePtr = top;

    while(nodePtr)
    {
        cout << nodePtr->info << endl;
        nodePtr = nodePtr->next;
    }
} // end print


#endif //DYNSTACK_H
