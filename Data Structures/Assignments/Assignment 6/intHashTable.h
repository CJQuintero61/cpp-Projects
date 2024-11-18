//Integer hash table
#include<iostream>
#include<iomanip>
using namespace std;

const int DEFAULT_TABLE_SIZE = 17;

class intHashTable 
{
	public:
		~intHashTable();
		intHashTable(int parameterSize = DEFAULT_TABLE_SIZE);
		int hashFunc(int);
		int add(int);
		bool search(int);
		void print();

	private:
		int *arr;
		int arrSize;
};

// Destructor 
intHashTable::~intHashTable()
{
	delete [] arr;
}

// Constructor
intHashTable::intHashTable (int parameterSize)
{
	if (parameterSize < 1)
	{
		cout << "Size of the hash table must be positive." << endl;
		cout << "Creating a hash table of size " << DEFAULT_TABLE_SIZE << "." << endl;
		arrSize = DEFAULT_TABLE_SIZE;
	}
	else
		arrSize = parameterSize; //set hash table size to parameter

	//***fill in the missing code here to declare the array and initialize all array elements to -1
    arr = new int[arrSize]; // make the array

    // set all elements to -1
    for(int i = 0; i < arrSize; i++)
        arr[i] = -1;

}

//---------------------------------------------------
// hashFunc
// Based on the value of new element, determine its index
//---------------------------------------------------
int intHashTable::hashFunc(int newVal) 
{
	//***fill in the missing code here to implement the division hashing function
    int location = newVal % arrSize;

    return location;
} // end hashFunc

//---------------------------------------------------
// add
// Adds a new node to the intHashTable
// Collisions are resolved by linear probing.
// Returns number of collisions too
//---------------------------------------------------
int intHashTable::add(int newVal) 
{
	//***fill in the missing code here to implement this function as requested

    int collisions = 0; // count the number of collisions that occur
    int location = hashFunc(newVal); // the subscript of the key
    bool found = false;

    while(arr[location] != -1 && !found)
    {
        if(arr[location] == newVal)
            found = true;
        else // apply linear probing algorithm
        {
            location = (location + 1) % arrSize;
            collisions++; // increment the collision counter
        }
    }
    if(found)
        cout << "Cannot add duplicate items.\n";
    else
        arr[location] = newVal;


    return collisions;
} // end add


//---------------------------------------------------
// search
// Searches through the intHashTable for 'key'. 
// Returns true if found and false otherwise
//---------------------------------------------------


bool intHashTable::search(int key) 
{
	//***fill in the missing code here to implement this function as requested
	int start = hashFunc(key); // the starting location
    int current = start; // holds the current subscript

    while(1)
    {
        // if an empty spot if found, stop searching because then the key doesn't exist
        if(arr[current] == -1)
            return false;
        // if the key is found, return true
        if(arr[current] == key)
            return true;

        // apply circular advancement
        current = (current + 1) % arrSize;

        // means the linear probing went through every value
        // and came back to the start meaning the key wasn't found
        if(current == start)
            return false;
    }
}


//---------------------------------------------------
// Outputs the entire list to the screen
//---------------------------------------------------
void intHashTable::print() 
{
	for(int i = 0; i < arrSize; i++)
		cout << setw(3) << i << ": " << setw(6) << arr[i] << endl;
	
	return;
}