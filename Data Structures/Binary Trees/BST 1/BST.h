#ifndef BINARYTREE
#define BINARYTREE

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
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

public:
    BinaryTree()
    { root = nullptr; }

    ~BinaryTree()
    { destroySubTree(root); }

    //operations
    void insertNode(T);
    bool searchNode(T);
    void remove(T);

    void displayInOrder() const
    { displayInOrder(root); }

    void displayPreOrder() const
    { displayPreOrder(root); }

    void displayPostOrder() const
    { displayPostOrder(root); }
};

template <class T>
void BinaryTree<T>::insertNode(T item)
{
    TreeNode *newNode = nullptr;

    newNode = new TreeNode;
    newNode->info = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}   // end insertNode


// uses recursion to find where to insert a new node
// nodePtr must be a reference to actually place a new node in the tree
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    // if the root is nullptr, make newNode the root node
    if(nodePtr == nullptr)
        nodePtr = newNode;
    else if(newNode->info < nodePtr->info) // traverse the left subtree
        insert(nodePtr->left, newNode);
    else                                   // traverse the right subtree
        insert(nodePtr->right, newNode);
}   // end insert

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->info << " ";
        displayInOrder(nodePtr->right);
    }
}   // end displayInOrder

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        cout << nodePtr->info << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}   // end displayPreOrder

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->info << " ";
    }
}   // end displayPostOrder

template <class T>
bool BinaryTree<T>::searchNode(T item)
{
    TreeNode *nodePtr = root;

    while(nodePtr)
    {
        if(nodePtr->info == item)
            return true;
        else if(item < nodePtr->info)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}   // end searchNode

template <class T>
void BinaryTree<T>::remove(T item)
{
    deleteNode(item, root);
}   // end remove


// nodePtr must be a reference to have access to actual nodes in the tree
// similar to how insert also needs access to those nodes
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
    if(item < nodePtr->info)
        deleteNode(item, nodePtr->left);
    else if(item > nodePtr->info)
        deleteNode(item, nodePtr->right);
    else
        makeDeletion(nodePtr);
}   // end deleteNode

// note that nodePtr POINTS to the node we want to delete
// therefore, it is the parent node of the node we want to delete
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // temporary pointer to reattach subtrees
    TreeNode *temp = nullptr;

    if(nodePtr == nullptr)
        cout << "Cannot delete from empty tree.\n";
    else if(nodePtr->right == nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->left; // reattach the left

        delete temp;
    }
    else if(nodePtr->left == nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->right; // reattach the right

        delete temp;
    }
    else // node has 2 children
    {
        // move one node to the right
        temp = nodePtr->right;
        // find the smallest node in the right subtree
        while(temp->left)
            temp = temp->left;
        // reattach the left subtree
        temp->left = nodePtr->left;
        temp = nodePtr;
        //reattach right subtree
        nodePtr = nodePtr->right;
        delete temp;
    }
}   // end makeDeletion

// used by destructor to destroy tree
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        if(nodePtr->left)
            destroySubTree(nodePtr->left);
        if(nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}   // end destroySubTree


#endif //BINARYTREE
