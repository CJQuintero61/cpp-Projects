#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    int top; // hold the top of the stack
    int stackSize; // hold the stack size
    T *stackArray; // pointer to the stack array

public:
    Stack(int); // constructor
    Stack(const Stack&); // copy constructor
    ~Stack(); // destructor

    // basic stack operations
    void push(T); // push an item onto the stack
    void pop(T&); // uses a reference variable to "catch" the popped value
    bool isEmpty() const; // returns true if stack is empty
    bool isFull() const; // returns true if stack is full
    T getTopItem() const; // gets the top item without removing it from the stack
    int getTop() const; // returns the top variable
    int getStackSize() const; // return the stack size
    void print() const; // print the stack items

    // math
    void add(); // adds the top 2 items together and pushes the sum
    void sub(); // subtracts the top 2 items and pushes the difference
    void mult(); // multiplies the top 2 items and pushes the product
    void div(); // divides the top 2 items and pushes the quotient
};

template <class T>
Stack<T>::Stack(int size)
{
    // set the stack size
    if(size > 0)
        stackSize = size;
    else
    {
        cout << "Cannot make a stack with a negative size.\n";
        cout << "Setting the stack size to 10.\n";
        stackSize = 10;
    }

    // set the top of the stack
    top = -1;

    // make the stack array
    stackArray = new T[stackSize];
} // end constructor

template <class T>
Stack<T>::Stack(const Stack &obj)
{
    // note that due to the constructor, stackSize is either a valid input
    // or it defaults to 10 if the user tries to enter 0 or less,
    // so we do not need to validate obj.stackSize here

   stackSize = obj.stackSize; // copy the stack size

   // copy the top
   top = obj.top;

   // make the array
   stackArray = new T[stackSize];

   // copy the contents
   for(int i = 0; i < stackSize - 1; i++)
       stackArray[i] = obj.stackArray[i];

} // end copy constructor

template <class T>
Stack<T>::~Stack()
{
    delete [] stackArray; // free the memory
    cout << "Stack deleted.\n";
} // end destructor

// pushes an item onto the stack
template <class T>
void Stack<T>::push(T item)
{
    if(isFull())
    {
        cout << "Cannot add item to a full stack.\n";
        return;
    }

    top++; // increment the top

    // add the item onto the top
    cout << "Pushing " << item << endl;
    stackArray[top] = item;
} // end push

// removes an item from the stack and copies it to a reference
template <class T>
void Stack<T>::pop(T &item)
{
    if(isEmpty())
    {
        cout << "Cannot remove item from an empty stack.\n";
        return;
    }

    // copy the item into the reference variable
    // this is our catch variable
    item = stackArray[top];

    cout << "Popping " << stackArray[top] << endl;
    top--; // remove the item
} // end pop

// returns true if the stack is empty
template <class T>
bool Stack<T>::isEmpty() const
{
    if(top == -1)
        return true;
    else
        return false;
} // end isEmpty

// returns true if the stack is full
template <class T>
bool Stack<T>::isFull() const
{
    if(top == stackSize - 1)
        return true;
    else
        return false;
} // end isFull

// returns the top item without removing it from the stack
template <class T>
T Stack<T>::getTopItem() const
{
    return stackArray[top];
}

// returns the top subscript
template <class T>
int Stack<T>::getTop() const
{
    return top;
} // end getTop

// returns the stack size
template <class T>
int Stack<T>::getStackSize() const
{
    return stackSize;
} // end getStackSize

// prints the stack
template <class T>
void Stack<T>::print() const
{
    if(top == -1)
    {
        cout << "Empty stack.\n";
        return;
    }

    for(int i = top; i > -1; i--)
    {
        cout << stackArray[i] << endl;
    }
} // end print

// adds top 2 items and pushes the sum
// works by adding top + (top - 1)
template <class T>
void Stack<T>::add()
{
    if(top <= 0)
    {
        cout << "Cannot add: There must be at least 2 items in the stack.\n";
        return;
    }

    T sum, item;
    pop(sum); // pop the top item
    pop(item); // pop the new top item
    sum += item;
    push(sum); // push sum back onto the stack
} // end add

// subtracts the top 2 items and pushes the difference
// works by subtracting the 2nd item from the top from the top item
// so, top - (top - 1) essentially
template <class T>
void Stack<T>::sub()
{
    if(top <= 0)
    {
        cout << "Cannot subtract: There must be at least 2 items in the stack.\n";
        return;
    }

    T diff, item;
    pop(diff); // pop the top item
    pop(item); // pop the new top item
    diff -= item;
    push(diff); // push the diff back onto the stack
} // end sub

// multiplies the top 2 items and pushes the product
template <class T>
void Stack<T>::mult()
{
    if(top <= 0)
    {
        cout << "Cannot multiply: There must be at least 2 items in the stack.\n";
        return;
    }

    T product, item;
    pop(product); // pop top item
    pop(item); // pop new top item
    product *= item;
    push(product); // push product back onto stack
} // end mult;

// divides the top 2 items and pushes the quotient
template <class T>
void Stack<T>::div()
{
    if(top <= 0)
    {
        cout << "Cannot divide: There must be at least 2 items in the stack.\n";
        return;
    }

    T quotient, item;
    pop(quotient); // pop top item
    pop(item); // pop the new top item
    quotient /= item;
    push(quotient); // push the quotient
} // end div

#endif //STACKTEMPLATE_H
