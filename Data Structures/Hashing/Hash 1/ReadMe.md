This program demonstrates separate chaining done in a hash table. That is, 
the code uses an array of linked lists to hash values to a certain subscript (hash value)
then stores them in the linked list. This heavily interested me after we learned about hashing.
If hashing is constant ( O(1) ), then I thought, why don't we only use hashing if it is way
more efficient than other sorting methods like selection sort and insertion sort. Also, hashing allows
quick and efficient searching and sorting so it is much better than using say, insertion sort and then binary search
is it not? Lastly, I still prefer linked lists over arrays so this further interested me. I first thought to make an 
array of linked lists all in one implementation file, but then found it much easier to code, and to follow along, when the 
code got split into a basic linked list file, and a hash array that allocated an array of linked lists. 
Onto the earlier point of why not always use hashing, I think hashing is commonly used in cyber security should I
get a career in that later on, but as with a lot of things in c++, there is times and places when certain things 
are better suited for the task. Also, for a noobie's code, I highly doubt that my code is as efficient as possible
but I was glad that I could get the general idea of using separate chaining and hashing down on my own.
I didn't really have any references nor did I copy any code. I only looked at our lecture slides that had an
array of linked lists as an image to visualize what was happening, then I did the rest.
CJ Quintero 11/26/2024
