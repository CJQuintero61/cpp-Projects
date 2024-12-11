/* CJ Quintero 12/10/2024
 * I decided to review and go through our book
 * for everything we learned, as my exam for data structures is
 * in 2 days on the 12th.
 * Good old recursion with the basic factorial
 * problem!
 */

#include <iostream>
using namespace std;

int factorial(int); // returns the factorial using recursion

int main()
{
    int num;
    cout << "Enter a positive integer.\n";
    cin >> num;
    cout << num << " factorial is: " << factorial(num) << endl;
    return 0;
}   // end main

int factorial(int x)
{
    if(x == 0)
        return 1; // base case
    else
        return x * factorial(x - 1); // recursive case
}   // end factorial