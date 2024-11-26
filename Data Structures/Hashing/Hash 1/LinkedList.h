#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:

    struct Node
    {
        T info;         // info of the current node
        Node *next;     // ptr to next node
    };

    Node *head;         // head of the linked list

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;        // returns true if the head points to nullptr
    bool search(const T &) const; // searches for a specific item

    void add(const T &);         // add a node to the end of the list
    void remove(const T &);      // remove a node
    void print() const;          // prints the linked list


};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;

    //cout << "Linked List created.\n";     // this is just a test message
}   // end constructor

template <class T>
LinkedList<T>::~LinkedList()
{
    Node *nodePtr = head;

    while(nodePtr)
    {
        head = nodePtr->next;
        delete nodePtr;
        nodePtr = head;
    }

    // test message
    // if(head == nullptr && nodePtr == nullptr)
    //    cout << "List successfully deleted.\n";
}   // end destructor

template <class T>
bool LinkedList<T>::isEmpty() const
{
    return (head == nullptr);
}   // end isEmpty

template <class T>
bool LinkedList<T>::search(const T &item) const
{
    bool found = false;
    Node *nodePtr = head;

    // traverse the list looking for a match
    while(nodePtr != nullptr)
    {
        if(nodePtr->info == item)
        {
            found = true;
            break;
        }
        nodePtr = nodePtr->next;
    }
    return found;
}   // end search

template <class T>
void LinkedList<T>::add(const T &item)
{
    if(isEmpty())
    {
        Node *newNode = new Node;   // make a new node
        newNode->info = item;       // store the info
        newNode->next = nullptr;    // make the new node point to null

        head = newNode;             // set the head to point to the new node
    }
    else
    {
        Node *nodePtr = head; // set nodePtr to the head

        // traverse the list to the last node
        while(nodePtr->next)
            nodePtr = nodePtr->next;

        Node *newNode = new Node;   // make a new node
        newNode->info = item;       // store the info
        newNode->next = nullptr;    // make the new node point to null

        nodePtr->next = newNode;    // connect the new node to the list
    }
}   // end add

template <class T>
void LinkedList<T>::remove(const T &item)
{
    if(isEmpty())
    {
        cout << "Cannot remove from empty list.\n";
        return;
    }

    // if the first node is to be deleted
    if(head->info == item)
    {
        Node *nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;
    }
    else
    {
        Node *nodePtr = head;
        Node *previousNode = head;

        // traverse the list
        while(nodePtr->info != item && nodePtr)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the item was found delete it and connect the links
        if(nodePtr->info == item)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}   // end remove

template <class T>
void LinkedList<T>::print() const
{
    if(isEmpty())
    {
        cout << "Emtpy list.\n";
        return;
    }
    else
    {
        Node *nodePtr = head;

        while(nodePtr)
        {
            cout << nodePtr->info << " ";
            nodePtr = nodePtr->next;
        }
    }
}   // end print






#endif //LINKEDLIST_H
