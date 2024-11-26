#ifndef HASHARRAY_H
#define HASHARRAY_H

#include <iostream>
#include "LinkedList.h"
using namespace std;



template <class T>
class HashArray
{
private:
    LinkedList<T> *arr; // array of linked lists
    int size;           // size of the array

    int hashFunction(const T &);    // hash function to store items and retrieve them
public:
    HashArray();
    HashArray(int s);
    ~HashArray();

    bool lookUp(const T &); // search for a specific item
    void store(const T &);  // store the item in its proper linked list
    void remove(const T &); // remove a certain item
    void printHash() const; // prints each linked list in the array

};

template <class T>
HashArray<T>::HashArray()
{
    size = 10;
    arr = new LinkedList<T>[size]; // make the array of linked lists
}   // end constructor

template <class T>
HashArray<T>::HashArray(int s)
{
    size = s;
    arr = new LinkedList<T>[size]; // make the array of linked lists
}   // end constructor

template <class T>
HashArray<T>::~HashArray()
{
    for(int i = 0; i < size; i++)
        arr[i].~LinkedList();

}   // end constructor

template <class T>
bool HashArray<T>::lookUp(const T &item)
{
    int loc = hashFunction(item); // get the hash subscript

    return arr[loc].search(item);
}   // end lookUp

template <class T>
void HashArray<T>::store(const T &item)
{
    int loc = hashFunction(item); // get the subscript location

    // do not allow duplicate items to be stored
    if(!arr[loc].search(item))
    {
        arr[loc].add(item); // add the item to the linked list
        return;
    }
    else
    {
        cout << "Cannot store duplicate items.\n";
        return;
    }
}   // end store

template <class T>
void HashArray<T>::remove(const T &item)
{
    int loc = hashFunction(item);

    // if found, remove it
    if(arr[loc].search(item))
    {
        arr[loc].remove(item);
        return;
    }
    else
    {
        cout << "Cannot remove item: item was not found in the hash array.\n";
        return;
    }
}   // end remove

template <class T>
void HashArray<T>::printHash() const
{
    for(int i = 0; i < size; i++)
    {
        cout << "Subscript [" << i << "]:\t";
        arr[i].print();
        cout << endl;
    }
}   // end printHash

template <class T>
int HashArray<T>::hashFunction(const T &item)
{
    return (item + 3) % size;   // + 3 is added to avoid clustering
}   // end hashFunction


#endif //HASHARRAY_H
