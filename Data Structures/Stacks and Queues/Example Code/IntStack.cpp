#include "IntStack.h"
#include <iostream>
using namespace std;


IntStack::IntStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1; // in an empty stack, the top is -1
} // end constructor

IntStack::IntStack(const IntStack &obj)
{
    // make the stack array
    if(obj.stackSize > 0)
        stackArray = new int[obj.stackSize];
    else
        stackArray = nullptr;

    // copy the stackSize
    stackSize = obj.stackSize;

    // copy the values
    for(int i = 0; i < stackSize; i++)
        stackArray[i] = obj.stackArray[i];

    // copy the tops
    top = obj.top;
} // end copy constructor

IntStack::~IntStack()
{
    delete [] stackArray;
} // end destructor

void IntStack::push(int num)
{
    if(isFull())
        cout << "The stack is full.\n";
    else
    {
        top++; // the top increases with each element added
        stackArray[top] = num;
    }
} // end push

void IntStack::pop(int &num)
{
    if(isEmpty())
        cout << "The stack is empty.\n";
    else
    {
        num = stackArray[top];
        top--; // the top decreases with each element removed
    }
} // end pop

bool IntStack::isFull() const
{
    bool status;

    if(top == stackSize - 1)
        status = true;
    else
        status = false;

    return status;
} // end isFull

bool IntStack::isEmpty() const
{
    bool status;

    if(top == -1)
        status = true;
    else
        status = false;

    return status;
} // end isEmpty

// pops 2 values off the stack, then pushes the sum back onto the stack
void IntStack::add()
{
    int num, sum;

    // pop the first 2 values off the stack
    pop(sum);
    pop(num);

    // add the 2 values
    sum += num;

    // push sam back onto the stack
    push(sum);

} // end add

// pops 2 values off stack, then pushes the difference back onto the stack
void IntStack::sub()
{
    int num, diff;

    // pop the 2 values
    pop(diff);
    pop(num);

    // subtract the 2
    diff -= num;

    // push the difference back onto stack
    push(diff);
}
