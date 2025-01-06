#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

template <class T>
class BinaryTree
{
private:
    struct TreeNode
    {
        T info;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    // private member functions
    void insertNode(TreeNode *&, TreeNode *&);
    void removeNode(T, TreeNode *&);
    void destroySubtree(TreeNode *);
    void makeDeletion(TreeNode *&);

    // traversal methods
    void displayPreorder(TreeNode *) const;
    void displayInorder(TreeNode *) const;
    void displayPostorder(TreeNode *) const;

public:
    BinaryTree()
    { root = nullptr; }

    ~BinaryTree()
    { destroySubtree(root); }

    void insert(T);
    void remove(T);
    bool search(T) const;

    // I had to define these outside the class (not inline) because of
    // something the compiler does when making templates and inline member functions
    void displayPreorder() const;
    void displayInorder() const;
    void displayPostorder() const;

};

// **************************************************************
// insert public member function:
// makes a new node then passes the new node and the root node to
// the private member function insertNode() to add the new node
// starting from the root of the tree
// **************************************************************
template <class T>
void BinaryTree<T>::insert(T item)
{
    // all inserted nodes get added as leaf nodes
    TreeNode *newNode = new TreeNode;
    newNode->info = item;
    newNode->left = newNode->right = nullptr;

    // insert the node in the private member function, starting at the root node
    insertNode(newNode, root);
}   // end insert

// **************************************************************
// insertNode private member function:
// inserts a new node into the tree
// **************************************************************
template <class T>
void BinaryTree<T>::insertNode(TreeNode *&newNode, TreeNode *&nodePtr)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->info < nodePtr->info)          // if newNode belongs in the left subtree
        insertNode(newNode, nodePtr->left);
    else                                            // if newNode belongs in the right subtree
        insertNode(newNode, nodePtr->right);
}   // end insertNode

// **************************************************************
// remove public member function:
// calls removeNode() private member function
// **************************************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
    removeNode(item, root);
}   // end remove

// **************************************************************
// removeNode private member function:
// recursively finds the node to be deleted then
// calls the makeDeletion() function
// **************************************************************
template <class T>
void BinaryTree<T>::removeNode(T item, TreeNode *&nodePtr)
{
    if (item < nodePtr->info)
        removeNode(item, nodePtr->left);
    else if (item > nodePtr->info)
        removeNode(item, nodePtr->right);
    else
        makeDeletion(nodePtr);
}   // end removeNode

// **************************************************************
// makeDeletion private member function:
// deletes the desired node and reconnects the branches
// if needed
// **************************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // temp TreeNode to reattach subtrees
    TreeNode *temp = nullptr;

    if(nodePtr == nullptr)
        cout << "Cannot remove from empty tree.\n";
    else if (nodePtr->left == nullptr)      // has a right subtree but no left
    {
        temp = nodePtr;
        nodePtr = nodePtr->right;   // reattach the right subtree

        delete temp; // delete the node
    }
    else if (nodePtr->right == nullptr)     // has a left subtree but no right
    {
        temp = nodePtr;
        nodePtr = nodePtr->left;   // reattach the left subtree

        delete temp;
    }
    else    // has 2 children
    {
        // move to the right node once
        temp = nodePtr->right;
        // find the leftmost node of the right subtree
        while(temp->left)
            temp = temp->left;
        temp->left = nodePtr->left;   // reattach to the left subtree of the node we want to delete
        temp = nodePtr;               // reset temp back to what we want to delete
        nodePtr = nodePtr->right;     // reattach the right subtree

        delete temp;
    }
}   // end makeDeletion

// **************************************************************
// search public member function:
// returns true if an item is found in the tree
// **************************************************************
template <class T>
bool BinaryTree<T>::search(T item) const
{
    TreeNode *nodePtr = root;

    // search the tree
    while (nodePtr)
    {
        if(nodePtr->info == item)
            return true;
        else if (item < nodePtr->info) // item is a part of the left subtree
            nodePtr = nodePtr->left;
        else                           // item is a part of the right subtree
            nodePtr = nodePtr->right;
    }

    return false;
}   // end search

// **************************************************************
// destroySubtree private member function:
// used by destructor to delete the entire tree
// **************************************************************
template <class T>
void BinaryTree<T>::destroySubtree(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        if (nodePtr->left)
            destroySubtree(nodePtr->left);
        if (nodePtr->right)
            destroySubtree(nodePtr->right);

        delete nodePtr;
    }
}   // end destroySubtree

// **************************************************************
// The next 3 traversal methods are as the name implies
// **************************************************************

template <class T>
void BinaryTree<T>::displayPreorder() const
{
    displayPreorder(root);
}   // end displayPreorder()

template <class T>
void BinaryTree<T>::displayPreorder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        cout << nodePtr->info << " ";
        displayPreorder(nodePtr->left);
        displayPreorder(nodePtr->right);
    }

}   // end displayPreorder(nodePtr)

template <class T>
void BinaryTree<T>::displayInorder() const
{
    displayInorder(root);
}   // end displayInorder()

template <class T>
void BinaryTree<T>::displayInorder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayInorder(nodePtr->left);
        cout << nodePtr->info << " ";
        displayInorder(nodePtr->right);
    }
}   // end displayInorder(nodePtr)

template <class T>
void BinaryTree<T>::displayPostorder() const
{
    displayPostorder(root);
}   // end displayPostorder()

template <class T>
void BinaryTree<T>::displayPostorder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayPostorder(nodePtr->left);
        displayPostorder(nodePtr->right);
        cout << nodePtr->info << " ";
    }
}   // end displayPostorder(nodePtr)




#endif // BINARYTREE_H
