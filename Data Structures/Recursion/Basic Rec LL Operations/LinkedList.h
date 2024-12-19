#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:

    struct ListNode
    {
        T info;
        ListNode *next;
    };

    ListNode *head;
    int nodeCount;

    // recursive LL operations
    int recCountNodes(ListNode *) const;       // used by recGetNodeCount()
    void recShowReverse(ListNode *) const;        // used by recPrintReverse()

public:
    LinkedList()
    { head = nullptr; nodeCount = 0; }
    ~LinkedList();

    void appendNode(const T &);               // add node to the end of LL
    void insertNode(const T &, int);          // add node in the middle of LL
    void deleteNode(const T &);               // delete a node by value
    void clearList();                         // delete every node in the list
    void print() const;                       // print the list using linear traversal

    bool isEmpty() const
    { return (head == nullptr); }             // returns true if there are no nodes in LL
    bool found(const T &) const;              // returns true if a value is found; do not allow duplicate values


    int getNodeCount() const                  // returns the current number of nodes in LL
    { return nodeCount; }

    // ----------Recursive LL Operations----------

    // uses recursion to get the node count
    // also the public interface that calls recCountNodes()
    int recGetNodeCount() const
    { return recCountNodes(head); }

    // uses recursion to print a list in reverse
    // calls the recShowReverse() function
    void recPrintReverse()
    { recShowReverse(head); }



};

template <class T>
LinkedList<T>::~LinkedList()
{
    // just to know when the destructor runs
    cout << endl << endl;
    cout << "---------- Running the Destructor ----------\n";
    clearList();
}

template <class T>
void LinkedList<T>::appendNode(const T &item)
{
    if(found(item))
    {
        cout << item << " is already in the list.\n";
        return;
    }

    ListNode *newNode = new ListNode;       // make a new node
    newNode->info = item;                   // store the info
    newNode->next = nullptr;                // since it will be the last node, set next to nullptr
    nodeCount++;                            // increment the current node count

    if(isEmpty())
    {
        head = newNode; // make the head point to the new node in an empty list
        return;         // careful programming
    }
    else
    {
        ListNode *nodePtr = head;

        while(nodePtr->next)    // find the last node
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}   // end appendNode

// This function works by considered the nodes as [0, N-1]
// where the head is node 0; This inserts the node into the [location] position
// for example, inserting a node at 3 will make it the 4th node in the list
// because we consider the 0th node; Think of it
// like array subscripts
template <class T>
void LinkedList<T>::insertNode(const T &item, int location)
{
    if(found(item))
    {
        cout << item << " is already in the list.\n";
        return;
    }

    ListNode *newNode = new ListNode;   // make a new node
    newNode->info = item;               // store the info
    nodeCount++;                        // increment node count

    // if list is empty or the node is to be the first node in the list
    if(isEmpty() || location <= 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode *nodePtr = head;
        int i = 0;

        while(i < location - 1 && nodePtr->next)
        {
            nodePtr = nodePtr->next;
            i++;
        }

        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }
}   // end insertNode

template <class T>
void LinkedList<T>::deleteNode(const T &item)
{
    if(!found(item))
    {
        cout << item << " was not found in the list.\n";
        return;
    }

    ListNode *nodePtr = head;
    ListNode *prevPtr = nullptr;
    nodeCount--;                    // decrease the node count

    // if the head is to be deleted
    if(head->info == item)
    {
        head = head->next;
        delete nodePtr;
        return;
    }

    // else traverse the list until item is found
    while(nodePtr->info != item)
    {
        prevPtr = nodePtr;
        nodePtr = nodePtr->next;
    }

    prevPtr->next = nodePtr->next;
    delete nodePtr;
}   // end deleteNode

template <class T>
void LinkedList<T>::clearList()
{
    if(isEmpty())
        cout << "Empty List.\n";
    else
    {
        ListNode *nodePtr = head;

        while(nodePtr)
        {
            head = nodePtr->next;
            delete nodePtr;
            nodeCount--;
            nodePtr = head;
        }
    }

    if(head == nullptr && nodeCount == 0)
        cout << "List successfully deleted.\n";
}   // end clearList

template <class T>
void LinkedList<T>::print() const
{
    if(isEmpty())
    {
        cout << "Empty List.\n";
        return;
    }
    else
    {
        ListNode *nodePtr = head;

        while(nodePtr)
        {
            cout << nodePtr->info << " ";
            nodePtr = nodePtr->next;
        }
    }
}   // end print

template <class T>
bool LinkedList<T>::found(const T &item) const
{
    bool found = false;

    // in an empty list, return not found
    if(isEmpty())
        return false;
    else
    {
        ListNode *nodePtr = head; // to traverse the list

        while(nodePtr && !found)  // check each node's info
        {
            if(nodePtr->info == item)
                found = true;
            nodePtr = nodePtr->next;
        }
    }

    return found;
}   // end found

template <class T>
int LinkedList<T>::recCountNodes(ListNode *ptr) const
{
    // general case: if there is a node, add 1 + remaining nodes
    if(ptr)
        return 1 + recCountNodes(ptr->next);
    else // stop when ptr reaches the end of the list (aka ptr == nullptr)
        return 0;
}   // end recCountNodes

template <class T>
void LinkedList<T>::recShowReverse(ListNode *ptr) const
{
    // general case: if there is another node, move to it
    // aka finds the last node in the list
    if(ptr->next)
        recShowReverse(ptr->next);

    // then once the last node is found, print the info then move
    // backwards in the function call stack which prints the nodes
    // in reverse
    cout << ptr->info << " ";
}

#endif //LINKEDLIST_H
