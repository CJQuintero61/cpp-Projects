#ifndef ASSIGNMENT_2_LINKEDLIST_H
#define ASSIGNMENT_2_LINKEDLIST_H
#include <iostream>
using namespace std;

// create a Linked List template to be used with many data types
template <class T>
class LinkedList
{
private:
    struct ListNode
    {
        ListNode *next; // point to the next node
        T value; // hold the data value
    };

    // list head pointer
    ListNode *head;
public:
    LinkedList(); // constructor
    ~LinkedList(); // destructor

    // basic Linked List operations
    void appendNode(T); // add a node to the end of the list
    void insertNode(T); // insert a node with a certain value
    void deleteNode(T); // delete a certain node
    void displayList() const; // print the list values

    // other operations
    int numNodes(); // count number of nodes
    int search(T); // search for a certain value and return that nodes position
    T getValueAt(int position); // return the value of a specific node
    T getTotal(); // add the values of every node
    T getAverage(); // average the values of every node
    T getLargest(); // get the largest value in the list
    int getLargestPosition(); // get the position (node number) of the largest value
    T getSmallest(); // get the smallest value in list
    int getSmallestPosition(); // get position (node number) of the smallest value
    void insertFront(T val); // insert a node at the front of the list
    void insertEnd(T val); // insert a node at the end of the list
    T deleteLast(); // delete the last node
    T deleteFront(); // delete the first node

    // Assignment 3 added functions
    void recursivePrint(int); // print the list in order with recursion
    void recursiveReversePrint(int); // print the list in reverse with recursion
    void recursivePrintEveryOther(int); // print every other node, so print nodes 0, 2, 4, 6, ...
    int recursiveNumNodes(int); // counts the number of nodes using recursion
    bool recursiveSequentialSearch(int, int); // uses recursion to check if a value is in the list

}; // end LinkedList class declaration

// constructor: this constructor simply sets the head to nullptr when a list is made
template <class T>
LinkedList<T>::LinkedList()
{
    // set the head to null
    head = nullptr;
} // end constructor

// destructor: the destructor destroys the list, that is, it deletes every node
// to free the allocated memory
template <class T>
LinkedList<T>::~LinkedList()
{
    // destroy the list

    // make a node to traverse the list
    ListNode *nodePtr;
    nodePtr = head; // set nodePtr to the start of the list

    while(nodePtr)
    {
        head = nodePtr->next; // move head to the node after nodePtr
        delete nodePtr; // delete the current node
        nodePtr = head; // move nodePtr back to the head
    }

    // if the head points to nullptr, then the list was deleted properly
    if(!head)
        cout << "List successfully deleted.\n";
    else
        cout << "The list was not deleted properly.\n";
}   // end destructor

// appendNode function: this function adds a new node to the end of the list
// regardless of the nodes value
template <class T>
void LinkedList<T>::appendNode(T val)
{
    // make the new node
    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = val; // store the value
    newNode->next = nullptr; // make the last node point to null

    // if the list is empty
   if(!head)
   {
       // set the head to point to the newNode (which is now the first node)
       head = newNode;
   }
   else
   {
       // make nodePtr to traverse the list
       ListNode *nodePtr;
       nodePtr = head;

       // move to the end of the list
       while(nodePtr->next)
           nodePtr = nodePtr->next;

       // append the node to the end
       nodePtr->next = newNode;
   }
} // end appendNode

// insertNode function: this function inserts a node depending on the value.
// this function assumes the list is sorted in a specific order as it will
// add the value after all values less than or equal to it
template <class T>
void LinkedList<T>::insertNode(T val)
{
    // make a new node
    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = val; // store the value



    // if the list is empty, make the head point to the new node, then set
    // the new node to point to null
    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        // make nodePtr to traverse the list
        // and previousNode to save the address of the previous node
        ListNode *nodePtr;
        ListNode *previousNode;

        // position nodePtr to the start of the list
        nodePtr = head;

        // if the node to be inserted is going to be first in the list, and the
        // list is NOT empty, then add it by doing this code
        if(newNode->value <= nodePtr->value)
        {
            newNode->next = nodePtr; // set the new node to point to the old first node
            head = newNode; // set the head to point to the new first node
        }
        else
        {
            // skip all values that are less than or equal to the new value
            // AND while nodePtr points to a node
            while(nodePtr && nodePtr->value <= val)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // insert the new node
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
} // end insertNode

// deleteNode function: this function will delete a node with a certain value
template <class T>
void LinkedList<T>::deleteNode(T val)
{
    // flag
    bool deletedProperly = false;

    if(!head)
    {
        cout << "Cannot delete a node from an empty list.\n";
        cout << endl;
    }
    else
    {
        ListNode *previousNode; // to hold address of previous node
        ListNode *nodePtr; // to hold address of current node

        // set nodePtr to the start of the list
        nodePtr = head;

        // if the first node is to be deleted
        if(nodePtr->value == val)
        {
            // set the head to point to the 2nd node
            head = nodePtr->next;
            delete nodePtr; // delete the first node
            deletedProperly = true; // update our flag
        }
        else
        {
            // traverse the list
            while(nodePtr)
            {
                if(nodePtr->value == val)
                {
                    // if the value is found, connect the previous node to the next node
                    previousNode->next = nodePtr->next;

                    delete nodePtr;
                    deletedProperly = true; // update the flag
                    break; // break out of the loop
                }

                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
        }
    }

    // give a message about the deletion status
    if(deletedProperly)
        cout << "Node value " << val << " successfully deleted.\n";
    else
        cout << "Node value " << val << " could not be deleted.\n";

} // end deleteNode

// displayList function:: this function prints values in the list
template <class T>
void LinkedList<T>::displayList() const
{
    // nodePtr traverses the list
    ListNode *nodePtr;
    nodePtr = head;

    // if the list is empty
    if(nodePtr == nullptr)
    {
        cout << "Empty list.\n";
        cout << endl;
    }
    else
    {
        // this loop prints the node values with a space in between
        while(nodePtr)
        {
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
    cout << endl; // print an empty line for readability
} // end displayList

// numNodes function: this function counts the number of nodes in the list
template <class T>
int LinkedList<T>::numNodes()
{
    int nodeCounter = 0;

    // nodePtr traverses the list
    ListNode *nodePtr;
    nodePtr = head;

    // if the list is empty, that means there are 0 nodes in the list
    if(!head)
        return 0;
    else
    {
        // traverse the list
        while(nodePtr)
        {
            nodePtr = nodePtr->next;
            nodeCounter++; // increment our counter
        }
    }
    return nodeCounter;
} // end numNodes

// search function: searches for a specific value and returns the position (node number)
// Important: This function is similar to array subscript, that is, node 0 holds value 1,
// node 1 holds value 2, and so in a list of 20 nodes, there are node positions 0 - 19
template <class T>
int LinkedList<T>::search(T val)
{
    // this will indicate that the list is empty
    if(!head)
        return 0;
    else
    {
        // if this else block runs, then there is at least 1 node
        int nodePosition = 0;
        bool found = false; // flag

        ListNode *nodePtr; // to traverse list
        nodePtr = head;

        while(nodePtr)
        {
            if(nodePtr->value == val)
            {
                found = true;
                break;
            }

            nodePtr = nodePtr->next;
            nodePosition++;
        }
        if(found)
            return nodePosition;
        else
            return -1; // this means the value wasn't found
    }
} // end search

// getValueAt function: returns the value of a node at a specific position
// IMPORTANT: this function is NOT parallel and is similar to an array's subscript
// for example, if there are 20 nodes, this function treats them as
// nodes 0 - 19 instead of 1 - 20
template <class T>
T LinkedList<T>::getValueAt(int position)
{
    if(!head)
    {
        cout << "Empty list.\n";
        cout << endl;
    }
    else
    {
        ListNode *nodePtr; // to traverse the list
        nodePtr = head;
        int counter = 0; // to count the node number

        if(position == 0)
            return nodePtr->value; // return the first node's value
        else
        {
            // if there are 20 nodes for example, and we want the 20th node,
            // this will return -100 because this function recognizes that there is
            // no 20th node, only nodes 0 - 19
            // I set these to return -100 because 0 and negative numbers
            // can be in the list, so I made a number that stands out more
            int numNodes = LinkedList::numNodes();
            if(position > numNodes - 1)
                return -100; // this means that the node wanted is out of range

            // move to the desired node
            while(nodePtr && counter < position)
            {
                nodePtr = nodePtr->next;
                counter++;
            }

            if(position == counter)
                return nodePtr->value;
            else // I believe this only runs if the position entered is a negative value
                return -100;
        }
    }
    return -100; // flag value
} // end getValueAt

// getTotal Function: gets the total value of all the nodes
template <class T>
T LinkedList<T>::getTotal()
{
    if(!head) // empty list
        return 0;
    else
    {
        // the data type of the list is unknown, so make it the same data type
        // as the values in the list, so a list of doubles uses a double as a total
        // and a list of ints uses an int as a total
        T total = 0;

        // traverse the list
        ListNode *nodePtr;
        nodePtr = head;

        while(nodePtr)
        {
            total += nodePtr->value;
            nodePtr = nodePtr->next;
        }
        return total;
    }
} // end getTotal

// getAverage function: gets the average of all values
template <class T>
T LinkedList<T>::getAverage()
{
    T total = LinkedList::getTotal(); // get the total
    double numNodes = LinkedList::numNodes(); // get the number of nodes

    return total/numNodes;
} // end getAverage

// getLargest function: gets the largest value in the list
template <class T>
T LinkedList<T>::getLargest()
{
    if(!head)
        return 0;
    else
    {
        T largest = head->value; // store the first value as the largest
        ListNode *nodePtr = head;

        // move through the list
        while(nodePtr)
        {
            // if a new largest value is found, store it in largest
            if(nodePtr->value > largest)
                largest = nodePtr->value;
            nodePtr = nodePtr->next;
        }
        return largest;
    }
} // end getLargest

// getLargestPosition function: gets the position of the largest value
template <class T>
int LinkedList<T>::getLargestPosition()
{
    if(!head)
        return -1; // in an empty list, return -1 (an invalid node position)
    else
    {
        T largest = LinkedList::getLargest(); // get the largest value;

        // this means the list is either empty, or the largest value is actually 0
        if(largest == 0)
            return -1;
        return LinkedList::search(largest);
    }
} // end getLargestPosition

// getSmallest function: gets the smallest value in the list
template <class T>
T LinkedList<T>::getSmallest()
{
    if(!head)
        return 0;
    else
    {
        T smallest = head->value; // store the first value as the smallest
        ListNode *nodePtr = head;

        // move through the list
        while(nodePtr)
        {
            // if a new smallest value is found, store it in smallest
            if(nodePtr->value < smallest)
                smallest = nodePtr->value;
            nodePtr = nodePtr->next;
        }
        return smallest;
    }
} // end getSmallest

// getSmallestPosition function: returns the position of the smallest value
template <class T>
int LinkedList<T>::getSmallestPosition()
{
    if(!head)
        return -1; // in an empty list, return -1 (an invalid node position)
    else
    {
        T smallest = LinkedList::getSmallest(); // get the smallest value;

        // this means the list is either empty, or the smallest value is actually 0
        if(smallest == 0)
            return -1;
        return LinkedList::search(smallest);
    }
} // end getSmallestPosition

// insertFront function: inserts a node to the front of the list
template <class T>
void LinkedList<T>::insertFront(T val)
{
    // make the new node and store the value
    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = val;

    // set the new node to point to the old first node
    newNode->next = head;
    head = newNode; // make the new node the new first node
} // end insertFront

// insertEnd function: insert an item at the end of the list
template <class T>
void LinkedList<T>::insertEnd(T val)
{
    // inserting a node at the end is the same as appending the node
    appendNode(val);
}

// deleteLast function: deletes the last node from the list
template <class T>
T LinkedList<T>::deleteLast()
{
    if(!head)
    {
        cout << "Cannot delete from an empty list.\n";
        cout << endl;
        return -100; // a flag value because this function must return something
    }
    else
    {
        T nodeValue; // hold the value from the deleted node
        ListNode *nodePtr = head;
        ListNode *previous;

        while(nodePtr->next)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }
        // nodePtr->next now points to nullptr
        // meaning nodePtr points to the last node
        nodeValue = nodePtr->value; // store the value we are deleting
        previous->next = nullptr; // set the 2nd to last node to point to nullptr
        delete nodePtr;

        return nodeValue;
    }

} // end deleteLast

// deleteFront function: deletes the first node
template <class T>
T LinkedList<T>::deleteFront()
{
    T nodeValue = head->value; // store the first value

    if(!head)
    {
        cout << "Cannot delete from an empty list.\n";
        cout << endl;
        return -100; // flag value because this function must return something
    }
    else
    {
        ListNode *nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;
        return nodeValue;
    }

} // end deleteFront

// recursivePrint functions: prints the linked list in order using recursion
template <class T>
void LinkedList<T>::recursivePrint(int numNodes)
{
    // in an empty list, do not call any recursive chains
    if(numNodes == 0)
    {
        cout << "Empty List.\n";
        return;
    }

    // base case is that there is only 1 node which the head points to
    if(numNodes == 1)
    {
        cout << head->value << " ";
    }
    else
    {
        recursivePrint(numNodes - 1);
        cout << getValueAt(numNodes - 1) << " ";
    }
    // getValueAt uses nodes like array subscripts so that position 0 is node 1
    // so that is why the 2nd statement in the else block passes numNodes - 1 to cout <<

} // end recursivePrint

// recursiveReversePrint function: prints a linked list in reverse order using recursion
template <class T>
void LinkedList<T>::recursiveReversePrint(int i)
{
    // here, we initially pass 0 as the parameter because nodes are counted
    // [0, N-1], and then use i as an iterator to build up to the last node
    // then work backwards to print the list in reverse

    if(!head) // in an empty list, do not call any recursive chains
    {
        cout << "Empty List.\n";
        return;
    }

    if(i  == numNodes() - 1)
    {
        cout << getValueAt(i) << " ";
    }
    else
    {
        recursiveReversePrint(i + 1);
        cout << getValueAt(i) << " ";
    }

} // end recursiveReversePrint

// recursivePrintEveryOther: prints every 2 nodes, so nodes 0, 2, 4, 6, ...
template <class T>
void LinkedList<T>::recursivePrintEveryOther(int i)
{
    if(numNodes() == 0) // in an empty list, do not call any recursive chains
    {
        cout << "Empty List.\n";
        return;
    }

    // in the first iteration, i == numNodes(), but i had to change the name numNodes to i
    // because I needed to use the numNodes() function
    if(i == 0)
    {
        cout << getValueAt(i) << " ";
    }
    else
    {
        recursivePrintEveryOther(i - 1);
        if(i% 2 == 0 && i < numNodes())
            cout << getValueAt(i) << " ";
    }
} // end recursivePrintEveryOther

// recursiveNumNodes: counts the number of nodes using recursion
template <class T>
int LinkedList<T>::recursiveNumNodes(int num)
{
    // if the head points to nullptr, then the list is empty and there are 0 nodes
    // this is the first thing checked in the function to make sure
    // an empty list doesn't call any recursive calls
    if(!head) // empty list
    {
        return 0;
    }

    // initially, num == 1, so we assume there is at least 1 node.
    // this is fine to be set to 1 because we use the head pointer
    // to check if there is no nodes, or if there is only 1 node

    // move nodePtr to the current next node
    ListNode *nodePtr = head;
    for(int i = 0; i < num; i++)
        nodePtr = nodePtr->next;


    if(!head->next) // if only 1 node
    {
        return 1;
    }
    else// there is more than 1 node
    {
        if(nodePtr->next) // if there is another node keep calling
            return recursiveNumNodes(num + 1);
        else
            return num + 1; // return the last node
    }

} // end recursiveNumNodes

// recursiveSequentialSearch: returns true if a value was found otherwise, returns false
template <class T>
bool LinkedList<T>::recursiveSequentialSearch(int numNodes, int val)
{
    // check this first
    if(!head)
    {
        return false; // empty list
    }

    // for the first call, start at the last node and work towards the first node
    ListNode *nodePtr = head;
    for(int i = 0; i < numNodes - 1; i++)
        nodePtr = nodePtr->next;

    if(nodePtr == head) // we reach the beginning of the list
    {
        if(nodePtr->value == val)
            return true;
        else
            return false;

    }
    else
    {
        // check the current node, if not equal, check the previous node, and so on
        // all the way until the first node
        // it does the sequential search, but backwards since it starts at the end of the list
        if(nodePtr->value == val)
            return true;
        else
            return recursiveSequentialSearch(numNodes - 1, val);

    }
}







#endif //ASSIGNMENT_2_LINKEDLIST_H
