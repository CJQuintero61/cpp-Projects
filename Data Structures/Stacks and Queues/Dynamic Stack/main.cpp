/*
 *
 *
 *
 *
 */

#include <iostream>
#include "DynStack.h"
using namespace std;

int main()
{
    cout << endl; // readability

    DynStack<int> stack1;
    int x; // integer catch variable

    // push some values
    stack1.push(5);
    stack1.push(10);
    stack1.push(15);
    stack1.push(20);
    cout << endl;

    stack1.print();
    cout << endl;

    stack1.pop(x);
    cout << x << " was popped.\n";
    stack1.pop(x);
    cout << x << " was popped.\n";
    cout << endl;

    stack1.print();
    cout << endl;

    stack1.pop(x);
    cout << x << " was popped.\n";
    stack1.pop(x);
    cout << x << " was popped.\n";
    cout << endl;

    stack1.print(); // stack should be empty here
    cout << endl;

    stack1.push(50);
    stack1.push(100);
    stack1.push(150);
    stack1.push(200);

    stack1.print();
    cout << endl;

    stack1.getTop(x);
    cout << "The top value is " << x << endl;
    cout << endl;


    return 0;
}