#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BinaryTree<int> tree;

    cout << "Inserting nodes.\n";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);

    cout << "Inorder Traversal.\n";
    tree.displayInOrder();
    cout << endl;

    cout << "Preorder Traversal.\n";
    tree.displayPreOrder();
    cout << endl;

    cout << "Postorder Traversal.\n";
    tree.displayPostOrder();
    cout << endl;

    cout << endl;
    cout << "Searching for 12.\n";
    if(tree.searchNode(12))
        cout << "12 was found in the tree.\n";
    else
        cout << "12 was not found in the tree.\n";
    cout << endl;

    cout << "Searching for 50.\n";
    if(tree.searchNode(50))
        cout << "50 was found in the tree.\n";
    else
        cout << "50 was not found in the tree.\n";
    cout << endl;

    cout << "Deleting node 5 (root with 2 subtrees).\n";
    tree.remove(5);
    cout << "Displaying inorder.\n";
    tree.displayInOrder();
    cout << endl;

    cout << "Displaying preorder (8 is the new root).\n";
    tree.displayPreOrder();
    cout << endl;


    return 0;
}   // end main