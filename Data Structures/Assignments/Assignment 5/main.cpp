#include <iostream>
#include <string>
#include "linkedQueueType.h"
#include "myStack.h"
using namespace std;

template <class T>
bool isPalindrome(string &, linkedQueueType<T> &, stackType<T> &);


int main()
{
    cout << endl; // readability
    linkedQueueType<int> Queue1;
    int num;


    for(int i = 0; i < 5; i++)
        Queue1.addQueue((i + 1) * 13); // add multiples of 13 to the queue

    cout << "Here is Queue1: ";
    Queue1.print();
    cout << endl << endl;

    cout << "Enter an integer to delete the corresponding node between [0, 4].\n";
    cin >> num;
    while(num < 0 || num > 4)
    {
        cout << "Invalid input: the node must be between [0, 4].\n";
        cout << "Enter a new integer.\n";
        cin >> num;
    }

    cout << "The item removed was: " << Queue1.removeNth(num);
    cout << endl << endl;

    cout << "Here is Queue1: ";
    Queue1.print();
    cout << endl << endl;

    cout << "***********************************\n";
    cout << "*          Question 2             *\n";
    cout << "***********************************\n";
    cout << endl;

    linkedQueueType<int> Queue2; // make a copy of Queue1
    Queue2 = Queue1;

    cout << "Making a copy of Queue1 called Queue2.\n";
    cout << "Here is Queue2: ";
    Queue2.print();
    cout << endl << endl;



    cout << "Comparing Queue2 to Queue1:\n";
    if(Queue1 == Queue2)
        cout << "The queues are the same.\n";
    else
        cout << "The queues are not the same.\n";
    cout << endl;

    cout << "Now adding to Queue2.\n";
    Queue2.addQueue(78);
    cout << endl;

    cout << "Here is Queue1: ";
    Queue1.print();
    cout << endl << endl;

    cout << "Here is Queue2: ";
    Queue2.print();
    cout << endl << endl;

    cout << "Comparing Queue2 to Queue1:\n";
    if(Queue1 == Queue2)
        cout << "The queues are the same.\n";
    else
        cout << "The queues are not the same.\n";
    cout << endl << endl;

    cout << "***********************************\n";
    cout << "*          Question 3             *\n";
    cout << "***********************************\n";
    cout << endl;

    cout << "Enqueuing to Queue2:\n";
    Queue2.addQueue(91);
    cout << "Here is Queue2: ";
    Queue2.print();
    cout << endl;
    linkedQueueType<int> Queue3, Queue4;

    cout << "Splitting the first half of Queue2 into Queue3 and the second half into Queue4.\n";
    Queue2.splitQueue(Queue3, Queue4);
    cout << endl;

    cout << "Here is Queue3: ";
    Queue3.print();
    cout << endl;

    cout << "Here is Queue4: ";
    Queue4.print();
    cout << endl;

    cout << "And here is Queue2 unchanged: ";
    Queue2.print();
    cout << endl;

    cout << "***********************************\n";
    cout << "*          Question 4             *\n";
    cout << "***********************************\n";
    cout << endl;


    stackType<char> Stk;        // to hold chars
    linkedQueueType<char> Q5;   // to hold chars
    string str;

    cout << "Enter a string.\n";
    cin.get();
    getline(cin, str);


    if(isPalindrome(str, Q5, Stk))
        cout << "The string is a palindrome.\n";
    else
        cout << "The string is not a palindrome.\n";






    return 0;
} // end main

template <class T>
bool isPalindrome(string &str, linkedQueueType<T> &Q, stackType<T> &Stk)
{
    char x;
    int i;

    // iterate through the string and convert each character to lowercase
    x = str[0];
    i = 0;
    while(x != '\0')
    {
        x = str[i];
        str[i] = tolower(x);
        i++;
    }

    // store each character into a stack and a queue
    for(int j = 0; j < str.length(); j++)
    {
        Q.addQueue(str[j]);
        Stk.push(str[j]);
    }

    char a, b; // to compare the stack and queue

    for(int k = 0; k < str.length(); k++)
    {
        a = Stk.top(); // get the top then remove it
        Stk.pop();
        b = Q.front(); // get the front then remove it
        Q.deleteQueue();

        if(a != b) // compare them
            return false;
    }

    return true;
} // end isPalindrome


