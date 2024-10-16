#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool powerOf7(int, int);
void reverseCharacters(string &, int, int);

int main()
{

    int num;
    cout << "Enter a value to test if it is a power of 7.\n";
    cin >> num;

    if(powerOf7(num, 0))
        cout << num << " is a power of 7.\n";
    else
        cout << num << " is not a power of 7.\n";


    string str;
    int start;
    int end;

    cout << "Enter a string:\n";
    cin >> str;
    cout << "Enter a starting value for the string:\n";
    cin >> start;
    cout << "Enter an ending value for the string:\n";
    cin >> end;
    cout << endl;

    cout << str << " in reverse is ";
    reverseCharacters(str, start, end);
    cout << str;

    return 0;
}

// returns true if the number entered is a power of 7
bool powerOf7(int num, int power)
{

    // stop once we reach a power of 7 that is greater than our number
    if(pow(7, power) >= num)
    {
        if(pow(7, power) == num)
            return true;
        else
            return false;
    }
    else // simply increases the power in the next recursive call
    {
        return powerOf7(num, power + 1);
    }
}

void reverseCharacters(string &str, int start, int end)
{

    if(start == end || start + 1 == end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        return;
    }
    else
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        reverseCharacters(str, start + 1, end - 1);
    }

}