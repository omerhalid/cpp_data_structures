//Inorder Successor in Binary Search Tree
//leetcode: https://leetcode.com/problems/inorder-successor-in-bst/
//https://www.geeksforgeeks.org/inorder-succesor-node-binary-tree/
//https://www.youtube.com/watch?v=5cPbNCrdotA   

//Inorder:
//left, root, right

//The idea is for this challenge is to find the inorder successor of a given node in a BST.
//In details it means that we need to find the node with the smallest value that is larger than the given node value.

/*Case 1:
Node has right subtree
Go deep to leftmost node in right subtree or find min in right subtree*/

/*Case 2:
No right subtree
Go to the nearest ancestor for which given node would be in left subtree*/

//We need to look at the ancestor only if there is no right subtree or the given node is the right child of its parent. Why? Because if the given node is the right child of its parent, then there is no inorder successor.

//Time complexity: O(h), where h is the height of the tree

//Study this again!!!

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* FindMin(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* Getsuccessor(Node* root, int data)
{
    //search the node - O(h)
    //We could have avoided this function call by passing the pointer to the node directly to Getsuccessor() function like "Node* Getsuccessor(Node* root, Node* current)"
    Node* current = Find(root, data); //Find() is a function that returns a pointer to the node with the given data
    if(current == NULL) //if the node with the given data doesn't exist
        return NULL;
    
    //Case 1: Node has right subtree (node with the smallest value that is larger than the given node value)
    if(current->right != NULL)
    {
        return FindMin(current->right); //FindMin() is a function that returns a pointer to the node with the smallest value in the tree
    }
    //Case 2: No right subtree
    else
    {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor; //so far this is the deepest node for which current node is in left
                ancestor = ancestor->left; //go to left. Why? Because we need to find the nearest ancestor for which given node would be in left subtree
            }
            else
            {
                ancestor = ancestor->right; //go to right. Why? Because we need to find the nearest ancestor for which given node would be in left subtree
            }
        }
        return successor;
    }
}