#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

template <class T>
class ArrayList
{
private:
    int size;           // size of the array
    int count;          // the number of items currently in the array
    T *list;            // the array

    void recQuicksort(int, int);            // to be used by quicksort()
    int recSearch(const T &, int, int) const;     // to be used by search()

    bool isFound(const T &) const;          // returns true if an item is found in the array.
    // to be used by add(). This is needed because when adding an item to the list,
    // the list will not be in order to perform binary search yet

    int partition(int, int);                // partition the array
    // to be used by recQuicksort()

    void swap(T &, T &);        // swaps two items in the array
    // to be used by partition()

public:
    ArrayList();
    ArrayList(int);
    ~ArrayList();

    int getSize() const;
    int getCount() const;
    int binarySearch(const T &) const;  // returns the subscript of the value being searched for
    // (recursive binary search)

    T getItem(int) const;             // returns the info at a specific subscript

    void add(const T &);        // adds an item to the end of the list
    void sub();                 // removes the last item in the list
    void quicksort();           // uses quicksort to sort the array Least->Greatest
    void print() const;         // print the list
};

template <class T>
ArrayList<T>::ArrayList()
{
    size = 10;              // default size is 10
    count = 0;              // initially 0 items in the list
    list = new T[size];     // make the array list of type T
}   // end constructor

// same as default constructor but with a specific size
template <class T>
ArrayList<T>::ArrayList(int s)
{
    size = s;
    count = 0;
    list = new T[size];
}   // end constructor

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] list;         // free the memory
    count = 0;              // set count to 0
    list = nullptr;         // avoid dangling pointers

    // destructor message
    cout << endl << endl;
    cout << "********** Destructor **********\n";
    cout << "List deleted.\n";
}   // end destructor

template <class T>
int ArrayList<T>::getSize() const
{
    return size;
}   // end getSize

template <class T>
int ArrayList<T>::getCount() const
{
    return count;
}   // end getCount

template <class T>
int ArrayList<T>::binarySearch(const T &item) const
{
    return recSearch(item, 0, size - 1);
}   // end search

template <class T>
int ArrayList<T>::recSearch(const T &item, int first, int last) const
{
    // stopping condition for item not found
    if(first > last)
        return -1; // returns an invalid subscript

    int mid = (first + last) / 2;

    if(item == list[mid]) // check the midpoint
        return mid;
    else if(item > list[mid]) // if item is in the upper half of the array
        return recSearch(item, mid + 1, last);
    else if(item < list[mid]) // if item is in the lower half of the array
        return recSearch(item, first, mid - 1);
}   // end recSearch

template <class T>
T ArrayList<T>::getItem(int loc) const
{
    if(count == 0)
    {
        return -65535;
    }
    // if the location is within the valid array range
    if(loc >= 0 && loc <= count - 1)
        return list[loc];
    else
    {
        // return the negative 16-bit integer limit.
        // A random value that I chose to return instead of using ASSERT
        return -65535;
    }
}   // end getItem

template <class T>
bool ArrayList<T>::isFound(const T &item) const
{
    for(int i = 0; i < count; i++)
    {
        if(list[i] == item)
            return true;
    }

    return false;
}   // end isFound

template <class T>
void ArrayList<T>::add(const T &item)
{
    bool found = isFound(item);

    if(!found && count != size)
    {
        // count contains the number of items in the array.
        // in the actual array, the last subscript is count - 1
        // so that is where the item gets stored
        count++; // increment the count
        list[count - 1] = item;

        // also, make sure that the array is not full
    }
    else if(found)
    {
        cout << item << " was found in the array.\n";
        cout << "Duplicate items are not allowed.\n";
    }
    else
    {
        cout << "Cannot add item to full list.\n";
    }
}   // end add

template <class T>
void ArrayList<T>::sub()
{
    if(count == 0)
        cout << "Cannot remove from empty List.\n";
    else
        count--;
}   // end sub

template <class T>
void ArrayList<T>::quicksort()
{
    recQuicksort(0, count - 1);
}   // end quicksort

template <class T>
void ArrayList<T>::recQuicksort(int first, int last)
{
    if(first < last)
    {
        int pivot;
        pivot = partition(first, last);           // partition the array
        recQuicksort(first, pivot - 1);      // quicksort the lower half
        recQuicksort(pivot + 1, last);      // quicksort the upper half
    }
}   // end recQuicksort

template <class T>
int ArrayList<T>::partition(int first, int last)
{
    int mid, pivotIndex, pivotValue;
    mid = (first + last) / 2;
    swap(list[first], list[mid]);           // move the pivot to the front
    pivotIndex = first;
    pivotValue = list[first];

    // traverse the list sorting values less than the pivot at the lower half of the array
    // and larger values at the upper half
    for(int i = first + 1; i <= last; i++)
    {
        if(list[i] < pivotValue)
        {
            pivotIndex++;
            swap(list[i], list[pivotIndex]);
        }
    }
    swap(list[first], list[pivotIndex]); // move pivot back to the middle of the array
    return pivotIndex;  // return the index for recursion
}   // end partition

template <class T>
void ArrayList<T>::swap(T &x,T &y)
{
    T temp = x;
    x = y;
    y = temp;
}   // end swap

template <class T>
void ArrayList<T>::print() const
{
    if(count == 0)
        cout << "Empty list.\n";
    else
    {
        for(int i = 0; i < count; i++)
            cout << list[i] << " ";
    }
}   // end print()


#endif  // ARRAYLIST_H
