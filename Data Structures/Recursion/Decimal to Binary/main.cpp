#include <iostream>
using namespace std;

void binary(int); // converts a positive integer to binary

int main()
{
    int num;

    cout << "Enter a positive integer.\n";
    cin >> num;
    cout << num << " in binary is: ";
    binary(num);


    return 0;
}   // end main

void binary(int x)
{
    if(x == 0) // base case 1: x reaches 0
        cout << 0;
    else if(x == 1) // base case 2: x reaches 1
        cout << 1;
    else if (x % 2 == 1) // odd number > 2, enter recursive chain
    {
        binary(x/2);
        cout << 1;  // after inner calls, print 1
    }
    else // even number > 2, enter recursive chain
    {
        binary(x/2);
        cout << 0; // after inner calls, print 0
    }
}   // end binary