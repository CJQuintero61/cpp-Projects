//Header file linkedQueue.h

#ifndef NodeType
#define NodeType

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

#endif

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue as a
// linked list.
//*************************************************************

template <class Type>
class linkedQueueType {
public:
    // copies half of a queue to the first queue then the other half to the second queue
    void splitQueue(linkedQueueType<Type> &, linkedQueueType<Type> &) const;

    bool operator==(const linkedQueueType<Type> &); // returns true if 2 queues are the same
    Type removeNth(Type); // remove the nth element from the queue
    void print() const; // print the queue

    const linkedQueueType<Type>& operator=
	(const linkedQueueType<Type>&);
	//Overload the assignment operator.
	
    bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	//    otherwise returns false.
	
    bool isFullQueue() const;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	//    otherwise returns false.
	
    void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: queueFront = NULL; queueRear = NULL
	
    Type front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	//    terminates; otherwise, the first element of the
	//    queue is returned.
	
    Type back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	//    terminates; otherwise, the last element of the
	//    queue is returned.
	
    void addQueue(const Type& queueElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement is
	//    added to the queue.
	
    void deleteQueue();
	//Function  to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first element
	//    is removed from the queue.
	
	void copyQueue(const linkedQueueType<Type>& otherQueue);
	// copy queue written by Yoav Kadosh (Therefore, be carefull!)

	
	linkedQueueType();
	//Default constructor
	
    linkedQueueType(const linkedQueueType<Type>& otherQueue);
	//Copy constructor
	
    ~linkedQueueType();
	//Destructor
	
private:
    nodeType<Type> *queueFront; //pointer to the front of the queue
    nodeType<Type> *queueRear;  //pointer to the rear of the queue
};

//Default constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
} //end default constructor

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;
	
    while (queueFront!= NULL)  //while there are elements left
		//in the queue
    {
        temp = queueFront;  //set temp to point to the
		//current node
        queueFront = queueFront->link;  //advance first to
		//the next node
        delete temp;    //deallocate memory occupied by temp
    }
	
    queueRear = NULL;  //set rear to NULL
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;
	
    newNode = new nodeType<Type>;   //create the node
	
    newNode->info = newElement; //store the info
    newNode->link = NULL;  //initialize the link field to NULL
	
    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
	
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the
		//first node
        queueFront = queueFront->link; //advance queueFront
		
        delete temp;    //delete the first node
		
        if (queueFront == NULL) //if after deletion the
			//queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


//Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
	initializeQueue();
} //end destructor

template <class Type>
void linkedQueueType<Type>::copyQueue
(const linkedQueueType<Type>& otherQueue) {
	
	nodeType<Type> *newNode, *current, *last;
	
    if (queueFront != NULL) //if queue is nonempty, make it empty
        initializeQueue();
	
    if (otherQueue.queueFront == NULL)
        queueFront = NULL;
    else {
        current = otherQueue.queueFront;  //set current to point
		//to the queue to be copied
		
        queueFront = new nodeType<Type>;  //create the node
		
        queueFront->info = current->info; //copy the info
        queueFront->link = NULL;  //set the link field of the
		//node to NULL
        last = queueFront;        //set last to point to the node
        current = current->link;    //set current to point to
		//the next node
		
		//copy the remaining queue
        while (current != NULL) {
            newNode = new nodeType<Type>;
			
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
		
		queueRear = last;
    }//end else
	
}


template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue) {
	
	if (this != &otherQueue) //avoid self-copy
        copyQueue(otherQueue);
	
    return *this;
	
} //end assignment operator

//copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) {
    queueFront = NULL;
    copyQueue(otherQueue);
}//end copy constructor

// **********************************************
// Assignment 5 added functions
// **********************************************

// simply prints the queue
template <class Type>
void linkedQueueType<Type>::print() const
{
    if (isEmptyQueue())
    {
        cout << "Empty queue.\n";
        return;
    }
    // make a node to traverse the queue
    nodeType<Type> *nodePtr = nullptr;
    nodePtr = queueFront;

    // traverse the queue
    while(nodePtr)
    {
        cout << nodePtr->info << " ";
        nodePtr = nodePtr->link;
    }
} // end print

template <class Type>
Type linkedQueueType<Type>::removeNth(Type num)
{
    assert(!isEmptyQueue()); // can't return something in an empty list

    // to traverse the list
    nodeType<Type> *nodePtr = nullptr;
    nodePtr = queueFront;

    // to point to the previous node
    nodeType<Type> *previousNode = nullptr;

    Type info; // to return

    if(num == 0)
    {
        // update the front
        queueFront = queueFront->link;
        info = nodePtr->info; // store the info
        delete nodePtr; // delete the old first node
        return info; // return the info that was deleted
    }

    for(int i = 0; i < num; i++)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->link;
    }

    // connect the previous node to the node 2 spots over
    previousNode->link = nodePtr->link;

    info = nodePtr->info;
    delete nodePtr; // delete the desired node

    return info;
} // end removeNth

template <class Type>
bool linkedQueueType<Type>::operator==(const linkedQueueType<Type> &obj)
{
    // if both queues are empty, they are equal
    if(this->isEmptyQueue() && obj.isEmptyQueue())
        return true;

    // make 2 node pointers and set one to the front of each queue
    nodeType<Type> *nodePtr1 = this->queueFront;
    nodeType<Type> *nodePtr2 = obj.queueFront;

    while(nodePtr1 || nodePtr2)
    {
        // if Ptr1 points to something and Ptr2 doesn't,
        // then Queue1 is longer and therefore not equal
        if(nodePtr1 && !nodePtr2)
            return false;
        // vise versa, this means that Queue2 is longer and therefore not equal
        if(nodePtr2 && !nodePtr1)
            return false;

        // if the values don't match
        if(nodePtr1->info != nodePtr2->info)
            return false;

        nodePtr1 = nodePtr1->link;
        nodePtr2 = nodePtr2->link;
    }

    return true;
} // end compare

template <class Type>
void linkedQueueType<Type>::splitQueue(linkedQueueType<Type> &Q1, linkedQueueType<Type> &Q2) const
{
    // for this function, the "Calling Queue" is the object that is referred to
    // by the "this" pointer

    int count = 0; // to count the nodes in the calling queue

    // if the calling Queue is empty, make Q1 and Q2 empty
    if(this->isEmptyQueue())
    {
        Q1.initializeQueue();
        Q2.initializeQueue();
        return;
    }

    // make a node to point to the start of the calling queue
    nodeType<Type> *nodePtr = this->queueFront;

    // count the nodes of the calling queue
    while(nodePtr)
    {
        count++;
        nodePtr = nodePtr->link;
    }

    if(count % 2 == 1)
    {
        cout << "Cannot split a queue with odd nodes.\n";
        return;
    }
    else // the calling queue must have an even number of nodes to split
    {
        nodePtr = this->queueFront; // reset nodePtr to the start of the queue
        Type info; // info of the calling queue's node

        for(int i = 0; i < count; i++)
        {
            if(i < count/2)
            {
                info = nodePtr->info;
                Q1.addQueue(info);
                nodePtr = nodePtr->link;
            }
            else
            {
                info = nodePtr->info;
                Q2.addQueue(info);
                nodePtr = nodePtr->link;
            }

        }

    }

} // end splitQueue



#endif
