#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<int> tree;

    cout << "Inserting nodes.\n";
    tree.insert(5);
    tree.insert(8);
    tree.insert(3);
    tree.insert(12);
    tree.insert(9);

    cout << "Inorder Traversal.\n";
    tree.displayInorder();
    cout << endl;

    cout << "Preorder Traversal.\n";
    tree.displayPreorder();
    cout << endl;

    cout << "Postorder Traversal.\n";
    tree.displayPostorder();
    cout << endl;

    cout << endl;
    cout << "Searching for 12.\n";
    if(tree.search(12))
        cout << "12 was found in the tree.\n";
    else
        cout << "12 was not found in the tree.\n";
    cout << endl;

    cout << "Searching for 50.\n";
    if(tree.search(50))
        cout << "50 was found in the tree.\n";
    else
        cout << "50 was not found in the tree.\n";
    cout << endl;

    cout << "Deleting node 5 (root with 2 subtrees).\n";
    tree.remove(5);
    cout << "Displaying inorder.\n";
    tree.displayInorder();
    cout << endl;

    cout << "Displaying preorder (8 is the new root).\n";
    tree.displayPreorder();
    cout << endl;


    return 0;
}   // end main