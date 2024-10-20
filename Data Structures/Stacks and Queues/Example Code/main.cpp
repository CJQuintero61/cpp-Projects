#include <iostream>
#include "IntStack.h"
using namespace std;

int main()
{
    int catchVariable; // holds the popped off value

    IntStack stack(5); // a stack with size 5

    cout << "Pushing 5\n";
    stack.push(5);
    cout << "Pushing 10\n";
    stack.push(10);
    cout << "Pushing 15\n";
    stack.push(15);
    cout << "Pushing 20\n";
    stack.push(20);
    cout << "Pushing 25\n";
    stack.push(25);
    cout << endl;

    // pop values off the stack
    cout << "Popping...\n";
    stack.pop(catchVariable);
    cout << catchVariable << endl;
    stack.pop(catchVariable);
    cout << catchVariable << endl;
    stack.pop(catchVariable);
    cout << catchVariable << endl;
    stack.pop(catchVariable);
    cout << catchVariable << endl;
    stack.pop(catchVariable);
    cout << catchVariable << endl;
    cout << endl << endl;


    // test isFull and isEmpty
    IntStack stack2(1);
    cout << "Testing isFull and isEmpty with a new stack:\n";
    stack2.pop(catchVariable);
    cout << endl;

    cout << "Filling the new stack completely:\n";
    stack2.push(50);
    stack2.push(100); // stack is full
    cout << endl;

    IntStack stack3(3);
    cout << "Adding and Subtracting stack values in a new stack:\n";
    cout << "Pushing 3.\n";
    stack3.push(3);
    cout << "Pushing 6.\n";
    stack3.push(6);
    cout << "Adding...\n";
    stack3.add();
    cout << "Popping the sum:\n";
    stack3.pop(catchVariable);
    cout << "The sum is " << catchVariable << ".\n";

    cout << "Pushing 10.\n";
    stack3.push(10);
    cout << "Pushing 7.\n";
    stack3.push(7);
    stack3.sub();
    cout << "Popping the difference.\n";
    stack3.pop(catchVariable);

    cout << "The difference is " << catchVariable << ".\n";


    return 0;
}