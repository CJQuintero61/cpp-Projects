/*
 * Christian Quintero 10/21/2024. This is a simple stack template with some basic functions
 * demonstrated in main, so I could practice working with stacks.
 */
#include <iostream>
#include "StackTemplate.h"
using namespace std;

int main()
{
    Stack<int> Stack1(5); // make a stack
    int catchVariable;

    cout << "The stack size of Stack 1 is " << Stack1.getStackSize() << endl;
    cout << "The top of Stack 1 is " << Stack1.getTop() << endl;
    cout << endl;

    cout << "Testing isEmpty and isFull:\n";
    cout << "Trying to remove from an empty stack:\n";
    Stack1.pop(catchVariable);
    cout << endl;

    for(int i = 0; i < 5; i++)
        Stack1.push(15 * (i+1));
    cout << endl;

    if(Stack1.isFull())
        cout << "The stack is now full.\n";

    cout << "Trying to add to a full stack:\n";
    Stack1.push(150); // stack is full so this won't be added
    cout << endl << endl;

    cout << "Getting the top item:\n";
    cout << Stack1.getTopItem() << endl << endl;

    cout << "Printing the stack:\n";
    Stack1.print();
    cout << endl;

    for(int i = 0; i < 5; i++)
        Stack1.pop(catchVariable);
    cout << endl;

    cout << "Trying to print an empty stack:\n";
    Stack1.print();
    cout << endl;

    for(int i = 0; i < 5; i++)
        Stack1.push(10 * (i + 1));
    cout << endl;

    cout << "Popping an item then printing the catch variable:\n";
    Stack1.pop(catchVariable);
    cout << "The catch variable is " << catchVariable << endl;
    cout << "Here is the stack after popping:\n";
    Stack1.print();
    cout << endl << endl;

    cout << "The catch variable is used to hold the popped item.\n";
    cout << "That item is no longer in the list but is saved in our catch variable\n";
    cout << "to be used however we need.\n";
    cout << "The catch variable is: " << catchVariable << endl;
    cout << endl;

    cout << "Adding:\n";
    Stack1.add();
    cout << "Here is Stack 1 after adding:\n";
    Stack1.print();
    cout << endl << endl;

    cout << "Subtracting:\n";
    Stack1.sub();
    cout << "Here is Stack 1 after subtracting:\n";
    Stack1.print();
    cout << endl << endl;

    cout << "Multiplying:\n";
    Stack1.mult();
    cout << "Here is Stack 1 after multiplying:\n";
    Stack1.print();
    cout << endl << endl;

    cout << "Dividing:\n";
    Stack1.div();
    cout << "Here is Stack 1 after dividing:\n";
    Stack1.print();
    cout << endl << endl;

    Stack1.push(1000);
    cout << "Dividing:\n";
    Stack1.div();
    cout << "Here is Stack 1 after dividing:\n";
    Stack1.print();
    cout << endl << endl;

    Stack<int> Stack2 = Stack1;

    cout << "Testing the copy constructor and making sure there\n";
    cout << "are no shallow copies.\n";
    cout << "(pointers in separate objects pointing to the same location)\n";
    cout << endl;

    cout << "Here is Stack 2 using the copy constructor:\n";
    Stack2.print();
    cout << endl;

    cout << "Here is Stack 1:\n";
    Stack1.print();
    cout << endl;

    cout << "Pushing to Stack 1:\n";
    Stack1.push(50);
    Stack1.push(100);
    cout << endl;

    cout << "Here is Stack 2:\n";
    Stack2.print();
    cout << endl;

    cout << "Here is Stack 1:\n";
    Stack1.print();
    cout << endl;



    return 0;
}