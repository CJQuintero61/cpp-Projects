#include <iostream>
using namespace std;

int fib(int);

// keep in mind that the 0th term is 0, and the 1st term is 1 and so on
// so it may appear to be 1 off in the sequence but
// it is working as intended
int main()
{
    int num;
    cout << "Enter a number to find the corresponding Fibonacci number:\n";
    cin >> num;
    cout << endl;
    cout << "Term " << num << " is " << fib(num) << " in the Fibonacci sequence.\n";
    cout << endl;

    cout << "Here are the first 10 terms of the sequence.\n";
    for(int i = 0; i < 10; i++)
        cout << fib(i) << ", ";

    return 0;
}   // end main

int fib(int num)
{
    if(num <= 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        return fib(num - 2) + fib(num - 1);
}