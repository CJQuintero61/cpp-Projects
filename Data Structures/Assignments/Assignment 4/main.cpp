/*
 * Assignment 4: Working with stacks
 * Given a linked list based stack template, this program makes 2 functions: evaluate, and binary.
 * Evaluate turns a postfix expression into a total such as 7 8 + will return 15. A stack is used to
 * evaluate the expression.
 * The binary function accepts an integer and returns a string of bits
 * that equals the base 10 value. A stack is used to do this as well.
 * Christian Quintero 10/24/2024
 */
#include <iostream>
#include <string>
#include "linkedStack.h"
using namespace std;

double evaluate(const string &); // converts a postfix expression into a double
string binary(int); //converts a number to its binary equivalent in a string

int main()
{
    cout << endl; // for readability

    string str;
    int num;

    cout << "Enter an equation in postfix notation with spaces in between.\n";
    getline(cin,str); // get the entire line
    cout << endl;

    cout << "After evaluating, the total is: " << evaluate(str) << endl;
    cout << endl;

    cout << "Enter a positive number to be converted to a binary string.\n";
    cin >> num;
    num = abs(num); // only display unsigned binary numbers
    cout << num << " in binary is: " << binary(num) << endl;
    cout << endl;




    return 0;
}

// accepts a string in postfix notation and returns the value back to main
// only works with single digits that are positive (0 - 9).
double evaluate(const string &str)
{
    linkedStackType<double> stack1;
    char a;
    double x, y;

    for(int i = 0; i < str.length(); i++)
    {
        a = str[i];
        x = double(a) - '0'; // convert a to a double stored in x

        if(a != '+' && a != '-' && a != '*' && a != '/' && a != ' ') // if a is a number
        {
            stack1.push(x);
        }
        else
        {
            if(a == '+')
            {
                y = stack1.top();
                stack1.pop();
                x = stack1.top();
                stack1.pop();

                stack1.push(x + y);
            } // end add
            else if(a == '-')
            {
                y = stack1.top();
                stack1.pop();
                x = stack1.top();
                stack1.pop();

                stack1.push(x - y);
            } // end subtract
            else if(a == '*')
            {
                y = stack1.top();
                stack1.pop();
                x = stack1.top();
                stack1.pop();

                stack1.push(x * y);
            } // end multiply
            else if(a == '/')
            {
                y = stack1.top();
                stack1.pop();
                x = stack1.top();
                stack1.pop();

                stack1.push(x / y);
            } // end divide

        } // end else

    } // end for loop

    return stack1.top(); // return the top (which is the total)
} // end evaluate

string binary(int num)
{
    linkedStackType<int> stack1;
    string str, c;
    int x;

    num = abs(num); // only accept positive integers
    int r; // remainder

    // fixes the problem of 0 not being shown when entering 0 to be
    // converted to binary. Check this first
    if(num == 0)
        return str = "0";

    while(num != 0)
    {
        r = num % 2; // store the remainder
        stack1.push(r); // push remainder onto stack
        num = num/2; // divide num
    }

    while(!stack1.isEmptyStack())
    {
        // get the top value
        x = stack1.top();
        stack1.pop(); // pop it off the stack

        // convert it to a string
        c = to_string(x);

        str += c;
    }
    return str;
}
