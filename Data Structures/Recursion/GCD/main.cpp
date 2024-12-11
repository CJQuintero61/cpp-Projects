#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
    int num, num2;
    cout << "Enter num 1:\n";
    cin >> num;
    cout << "Enter num 2:\n";
    cin >> num2;
    cout << endl;

    cout << "The GCD of " << num << " and " << num2 << " is: " << gcd(num, num2) << endl;
}   // end main

// find the gcd using Euclid's algorithm
int gcd(int x, int y)
{
    if(x % y == 0) // if y divides x evenly (no remainder)
        return y;
    else
        return gcd(y, x % y);
}   // end gcd