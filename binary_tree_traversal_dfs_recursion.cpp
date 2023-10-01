//Problem statement link: https://leetcode.com/problems/binary-tree-inorder-traversal/

//Tree is not a linear data structure, so we can't traverse it in a linear way.
//we can have more than one possible directions to traverse the tree.

//Tree traversal: visiting each node in the tree exactly once.

//BFS: breadth first search: level order traversal
//DFS: depth first search: preorder, inorder, postorder traversal

//Preorder traversal: root, left, right
//Inorder traversal: left, root, right (gives sorted order for BST)
//Postorder traversal: left, right, root

//preorder implementation using recursion:
//Time complexity: O(n)
//Space complexity: worst O(n), best/average O(log n)

// 1. visit the root
// 2. traverse the left subtree
// 3. traverse the right subtree

#include <iostream>

using namespace std;

struct Node
{
    char data; 
    Node *left;
    Node *right;
};

void Preorder(Node *root)
{
    if(root == NULL) return;
    
    cout << root->data << " "; //visit the root
    Preorder(root->left); //traverse the left subtree
    Preorder(root->right); //traverse the right subtree

    //this function will return when the root is null, that is when we reach the leaf node. 
}  

void Inorder(Node *root) //gives sorted order for BST
{
    if(root == NULL) return;

    Inorder(root->left); //traverse the left subtree
    cout << root->data << " "; //visit the root
    Inorder(root->right); //traverse the right subtree
}

void Postorder(Node *root)
{
    if(root == NULL) return;

    Postorder(root->left); //traverse the left subtree
    Postorder(root->right); //traverse the right subtree
    cout << root->data << " "; //visit the root
}

int main(){
    //constructing the tree
    Node *root = new Node();
    root->data = 'A';
    root->left = new Node();
    root->left->data = 'B';
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = new Node();
    root->right->data = 'C';
    root->right->left = NULL;
    root->right->right = NULL;
    root->left->left = new Node();
    root->left->left->data = 'D';
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = new Node();
    root->left->right->data = 'E';

    cout << "Preorder traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    Postorder(root);
    cout << endl;

    return 0;
}