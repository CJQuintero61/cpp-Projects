#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
bool isPalindrome(LinkedList<T>&, int, int);

int main()
{
    LinkedList<int> List1;
    List1.appendNode(3);
    List1.appendNode(4);
    List1.appendNode(4);
    List1.appendNode(3);

    LinkedList<int> List2;

    for(int i = 0; i < 9; i++)
        List2.appendNode(13 * (i+1)); // fill another list with values

    cout << "Here is list 1:\t";
    for(int i = 0; i < List1.numNodes(); i++)
        cout << List1.getValueAt(i) << " ";
    cout << endl;


    if( isPalindrome(List1, 0, List1.numNodes() - 1) )
        cout << "List 1 is a palindrome.\n";
    else
        cout << "List 1 is not a palindrome.\n";
    cout << endl << endl;


    cout << "Here is list 2:\t";
    for(int i = 0; i < List2.numNodes(); i++)
        cout << List2.getValueAt(i) << " ";
    cout << endl;

    if( isPalindrome(List2, 0, List2.numNodes() - 1) )
        cout << "List 2 is a palindrome.\n";
    else
        cout << "List 2 is not a palindrome.\n";
    cout << endl << endl;

    return 0;
}

template <class T>
bool isPalindrome(LinkedList<T>& List, int start, int end)
{

    // works by "narrowing inwards" into the center of the list and testing the
    // outermost values, then works inward to the center
    if(start == end || start + 1 == end)
    {
        if(List.getValueAt(start) == List.getValueAt(end))
            return true;
        else
            return false;
    }
    else
        if(List.getValueAt(start) == List.getValueAt(end))
            return isPalindrome(List, start + 1, end - 1);
        else
            return false;
}