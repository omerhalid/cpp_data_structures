//Check if a given tree is binary tree or not

//Leeetcode problem: https://leetcode.com/problems/validate-binary-search-tree/

//Binary search tree: left subtree < root < right subtree

//Difference between binary tree and binary search tree is that in binary tree, left subtree < root < right subtree is not true.

//Instead of this recursive approach we could find the max value in left subtree and min value in right subtree and compare it with root value.

//Explanation: https://www.youtube.com/watch?v=yEwSGhSsT0U
//Time complexity: O(n)

//We can also do inorder traversal and check if the array is sorted or not. If it is sorted then it is a BST.

/*
The approach verifies if a binary tree is a BST using recursion. 
- `IsBstUtil` checks if the current node's value lies between a valid range (minValue, maxValue).
- For the left child, the current node's value becomes the new maxValue.
- For the right child, the current node's value becomes the new minValue.
- `IsBinarySearchTree` initializes the check with the full integer range for the root node.
*/


#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/*
Time complexity: O(n^2)
bool IsSubtreeLesser(Node *root, int value)
{
    if(root == NULL) return true;

    if(root->data <= value
        && IsSubtreeLesser(root->left, value)
        && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(Node *root, int value)
{
    if(root == NULL) return true;

    if(root->data > value
        && IsSubtreeGreater(root->left, value)
        && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}*/

//Depending in the sitaution you might want to use long long min, long long max instead of int min, int max because the values might overflow.
bool IsBstUtil(Node* root, int minValue, int maxValue)
{
    if(root == NULL) return true;

    if(root->data > minValue
        && root->data < maxValue
        && IsBstUtil(root->left, minValue, root->data) //left subtree should be less than root
        && IsBstUtil(root->right, root->data, maxValue)) //right subtree should be greater than root
        return true;
    else
        return false;
}

bool IsBinarySearchTree(Node *root)
{
    return IsBstUtil(root, INT_MIN, INT_MAX);
}