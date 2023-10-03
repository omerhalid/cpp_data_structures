//Delete a node from a BST

//Here will be explained how to delete a node from a BST. There are three cases:
//1. Node to be deleted is a leaf node
//2. Node to be deleted has only one child
//3. Node to be deleted has two children

//The trick for two children case is to find the minimum value in the right subtree, 
//copy the value int targetted node, delete dublicate from right subtree.
//You can do the same for maximum value in the left subtree.

//Recursion approach:
/**
 * Delete a node with a given value from a Binary Search Tree (BST).
 * 
 * Scenarios for node deletion:
 * 1. Leaf Node (No Children): Directly remove the node.
 * 2. Node with One Child: Bypass the node and link its parent to its child.
 * 3. Node with Two Children: Replace the node with the node containing the
 *    smallest value in its right subtree (or the largest in its left subtree).
 *    Then delete the node used for replacement.
 * 
 * @param root Pointer to the root of the BST.
 * @param data The value to be deleted.
 * @return Pointer to the root of the (potentially modified) BST.
 */

/*Function Delete(Node: root, Integer: data) -> Node:
    If root is NULL then:
        Return NULL

    If data < root's data then:
        Set root's left child to Delete(root's left child, data)
    Else if data > root's data then:
        Set root's right child to Delete(root's right child, data)
    Else:
        // Node with given data found!
        If both root's left child and right child are NULL then:
            // Node is a leaf node.
            Delete root
            Set root to NULL
        Else if root's left child is NULL then:
            // Node has only right child.
            Create Node pointer temp and set it to root
            Set root to root's right child
            Delete temp
        Else if root's right child is NULL then:
            // Node has only left child.
            Create Node pointer temp and set it to root
            Set root to root's left child
            Delete temp
        Else:
            // Node has two children.
            Create Node pointer temp and set it to minimum node in root's right subtree (using FindMin function)
            Set root's data to temp's data
            Set root's right child to Delete(root's right child, temp's data) 

    Return root
End Function
*/
/*    else if(data < root->data):
        This checks if the value (data) you're looking to delete is less than the current node's (root) value.
        If it is, you know the node (if it exists) must be in the left subtree of the current node.
        Therefore, the code calls the Delete function recursively on the left subtree: Delete(root->left, data).
        After this recursive call, you might have a new left child (because you might have deleted the original left child, or made changes in the subtree). So, you update the left child of the current node with the result of the deletion operation: root->left = ....

    else if(data > root->data):
        This checks if the value (data) you're looking to delete is greater than the current node's (root) value.
        If it is, you know the node (if it exists) must be in the right subtree of the current node.
        So, just like the previous case but for the right child, the code calls the Delete function recursively on the right subtree: Delete(root->right, data).
        And you update the right child of the current node accordingly: root->right = ....

By following this process, you're essentially navigating the BST to find the node you wish to delete, and along the way, you may perform deletions or changes in the structure of the tree.*/
#include <iostream>

using namespace std;

struct Node
{
    int data; 
    Node *left;
    Node *right;
};

Node* Delete(Node *root, int data)
{
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data); // if the data is less than the root, then it lies in left subtree
    else if(data > root->data) root->right = Delete(root->right, data); // if the data is greater than the root, then it lies in right subtree
    else //Wohoo... I found you, Get ready to be deleted
    {
        //Case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: One child 
        else if(root->left == NULL)
        {
            Node *temp = root; //Storing the root in a temp variable because we are going to delete root
            root = root->right; //Pointing root to right child
            delete temp; //Deleting the old root
        }
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: 2 children
        else
        {
            Node *temp = FindMin(root->right); // adress of the minimum value in the right subtree (to be implemented)
            root->data = temp->data; //copying the value of the minimum value in the right subtree to the targetted node
            root->right = Delete(root->right, temp->data); //deleting the dublicate
        }
    }
    return root;
}