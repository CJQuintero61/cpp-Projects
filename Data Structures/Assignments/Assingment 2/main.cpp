#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>* function1(LinkedList<T> *L1, LinkedList<T> *L2); // merges 2 linked lists

template <typename T>
bool function2(LinkedList<T> *L1, LinkedList<T> *L2); // compares 2 lists' length, and values



int main()
{
    // make a list
    // in this list, values with a decimal will represent values inserted or appended
    // to easily distinguish from the initial list values
    LinkedList<double> list1;

    // make a list with values from [1, 20]
    // also tests appendNode function and display list
    for(int i = 0; i < 20; i++)
    {
        list1.appendNode(i+1);
    }
    cout << "Here are the starting values for list 1:\n";
    list1.displayList();


    // testing inserting at the front, middle, and end
    cout << "Inserting nodes at the front, middle, and end of list 1:\n";
    list1.insertNode(0.5);
    list1.insertNode(10.5);
    list1.insertNode(20.5);
    list1.displayList();

    // testing deleting a node at the front, middle, and end
    cout << "Deleting nodes at the front, middle, and end of list 1:\n";
    list1.deleteNode(0.5);
    list1.deleteNode(10.5);
    list1.deleteNode(20.5);
    list1.displayList();

    // count the nodes
    cout << "There are " << list1.numNodes() << " nodes in list 1.\n";

    // get the node position for a certain value
    // a position of 0 means the list is empty
    // a position of -1 means the value wasn't found
    cout << "Value 12 is located at node " << list1.search(12) << ".\n";
    cout << endl;

    // Testing the getValueAt function
    cout << "Testing the getValueAt function for list 1:\n";
    cout << "A value of -100 means that the node position could not be found.\n";
    cout << "Node 0 has a value of: " << list1.getValueAt(0) << endl;
    cout << "Node 5 has a value of: " << list1.getValueAt(5) << endl;
    cout << "Node 19 has a value of: " << list1.getValueAt(19) << endl;
    cout << "Node 20 has a value of: " << list1.getValueAt(20) << endl;
    cout << "Node -1 has a value of: " << list1.getValueAt(-1) << endl;
    cout << endl;


    cout << "Getting the total of list 1:\n";
    cout << "The total of list 1 is: " << list1.getTotal() << endl;
    cout << endl;

    cout << "Getting the average of list 1:\n";
    cout << "The average of list 1 is: " << list1.getAverage() << endl;
    cout << endl;

    cout << "Getting the largest of list 1:\n";
    cout << "The largest of list 1 is: " << list1.getLargest() << endl;
    cout << endl;

    cout << "Getting the position of the largest value in list 1:\n";
    cout << "The position of the largest value in list 1 is node " << list1.getLargestPosition() << endl;
    cout << endl;

    cout << "Getting the smallest of list 1:\n";
    cout << "The smallest of list 1 is: " << list1.getSmallest() << endl;
    cout << endl;

    cout << "Getting the position of the smallest value in list 1:\n";
    cout << "The position of the smallest value in list 1 is node " << list1.getSmallestPosition() << endl;
    cout << endl;

    cout << "Inserting at the front of list 1:\n";
    list1.insertFront(300);
    list1.displayList();
    cout << endl;

    cout << "Inserting at the end of list 1:\n";
    list1.insertEnd(500);
    list1.displayList();
    cout << endl;

    cout << "Deleting the last node of list 1:\n";
    cout << "Node value " << list1.deleteLast() << " was deleted from the end.\n";
    list1.displayList();
    cout << endl;


    cout << "Deleting the front node of list 1:\n";
    cout << "Node value " << list1.deleteFront() << " was deleted from the front.\n";
    list1.displayList();
    cout << endl;



    cout << "******************************************************************************\n";
    cout << "Problem 2:\n";

    // multiples of 10 from 10 - 100
    LinkedList<int> list2;
    for(int i = 0; i < 10; i++)
        list2.appendNode((i+1) * 10);

    // multiples of 5 from 5 - 95
    LinkedList<int> list3;
    for(int i = 0; i < 10; i++)
        list3.appendNode(((i+1) * 10) - 5);
    list3.appendNode(105);
    list3.appendNode(115);

    cout << "Here is list 2:\n";
    list2.displayList();
    cout << endl;
    cout << "Here is list 3:\n";
    list3.displayList();
    cout << endl;


    LinkedList<int> *list2Ptr = &list2;
    LinkedList<int> *list3Ptr = &list3;
    LinkedList<int> *list4 = function1(list2Ptr, list3Ptr);
    cout << "Merging list 2 and list 3:\n";
    cout << "Here is list 4:\n";
    list4->displayList();

    cout << "Once again, here is list 2:\n";
    list2.displayList();
    cout << endl;

    cout << "And here is list 3 again:\n";
    list3.displayList();
    cout << endl;

    cout << "Comparing list 2 and list 3:\n";
    if(function2(list2Ptr, list3Ptr))
        cout << "The lists are the same.\n";
    else
        cout << "The lists are not the same.\n";
    cout << endl;


    LinkedList<int> List5;
    for(int i = 0; i < 10; i++)
        List5.appendNode((i+1) * 10);
    LinkedList<int> *list5Ptr = &List5;

    cout << "Here is list 5:\n";
    List5.displayList();
    cout << endl;

    cout << "Comparing list 2 and list 5:\n";
    if(function2(list2Ptr, list5Ptr))
        cout << "The lists are the same.\n";
    else
        cout << "The lists are not the same.\n";
    cout << endl;


    return 0;
} // end main

// this is going to take some explaining as this is made sense in my mind
// and is probably not the optimal way to merge 2 linked lists
// function1: merges 2 linked lists
template <typename T>
LinkedList<T>* function1(LinkedList<T> *L1, LinkedList<T> *L2)
{
    LinkedList<T> *newList; // make the new list
    newList = new LinkedList<T>;


    if(L1->head == nullptr) // if list 1 is empty, return list 2
        return newList = L2;
    else if(L2->head == nullptr) // if list 2 is empty, return list 1
        return newList = L1;
    else
    {
        T List1Value; // to hold node value i of list 1
        T List2Value;// to hold node value i of list 2
        int LargerNodeAmount; // to know how many times we must iterate the loop

        // find which list is longer
        if(L1->numNodes() > L2->numNodes())
            LargerNodeAmount = L1->numNodes();
        else
            LargerNodeAmount = L2->numNodes();


        for(int i = 0; i < LargerNodeAmount; i++)
        {
            // store the value of both lists using i as the index
            List1Value = L1->getValueAt(i);
            List2Value = L2->getValueAt(i);

            // if L1 value at i is smaller, append it to the new list
            // but if the value is stored as -100, that means the end of list 1 was reached
            // but we still need to append list 2's values, and that is what the inner if block
            // does. If list 1 and list 2 still have elements to go through, simply compare
            // and append whichever is smaller, then followed by the next
            if(List1Value < List2Value)
            {
                if(List1Value == -100)
                {
                    newList->appendNode(List2Value);
                    continue;
                }
                newList->appendNode(List1Value);
                newList->appendNode(List2Value);
            }
            else
            {
                if(List2Value == -100)
                {
                    newList->appendNode(List1Value);
                    continue;
                }

                newList->appendNode(List2Value);
                newList->appendNode(List1Value);
            }
            // same thing here, if L2's value is -100, that means the end of L2 was reached
            // but there is still values in L1 to append
            // otherwise, append the L2's value because it is smaller, then append L1's value which
            // goes after it
            // **********************************************************************************
            // Basically, the inner if blocks are needed when the 2 lists are not the same length
            // **********************************************************************************
        }
        return newList; // return the list
    }
} // end funciton1

// function2: returns true if both lists are the same
template<typename T>
bool function2(LinkedList<T> *L1, LinkedList<T> *L2)
{
    //first check the node lengths
    if(L1->numNodes() != L2->numNodes())
        return false;
    else
    {
        // then check each value
        T L1Value;
        T L2Value;

        for(int i = 0; i < L1->numNodes(); i++) // lists are same length
        {
            L1Value = L1->getValueAt(i);
            L2Value = L2->getValueAt(i);

            if(L1Value  != L2Value)
                return false;
        }

        // lists have same length and values
        return true;
    }
} // end function2
