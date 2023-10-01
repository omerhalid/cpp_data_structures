//Find height of a binary tree

//height of a tree means the number of edges from the root node to the deepest leaf node
//depth of a node means the number of edges from the root node to that node

//High level explanation:
//1. If the tree is empty, return -1
//2. If the tree is not empty, return the maximum of the height of the left subtree and the height of the right subtree + 1
//3. The height of the tree is the height of the root node

//Explanation with visualization:
//https://www.youtube.com/watch?v=_pnqMz5nrRs

//Time complexity: O(n)
//Space complexity: O(n) because of the recursive calls

/*Problem Statement

You are given a binary tree, and you want to find its maximum depth. The depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.
The Approach

The solution uses a recursive approach to determine the depth. The base case is when the given node (or root in this case) is nullptr.
Code Explanation

    Base Case:

    cpp

if(root == nullptr){
    return 0;
}

If the current node (or root) is nullptr, it means there's no tree from this node, and hence the depth is 0.

Recursive Calls:

cpp

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        maxDepth(root->left): This is a recursive call that calculates the depth of the left subtree.
        maxDepth(root->right): This is another recursive call that calculates the depth of the right subtree.
        max( ... ): Among the depths returned by the two recursive calls, we pick the maximum one, since we want the longest path.
        + 1: We add 1 to the result because we need to count the current node as well.

    The function eventually returns the maximum depth of the binary tree.

How It Works

Imagine you have a tree:

markdown

    1
   / \
  2   3
 / \
4   5

The calls would be made in the following manner:

    maxDepth(node with value 1)
        Checks left subtree (2) and right subtree (3).
        For left subtree (2):
            Checks left subtree (4) and right subtree (5).
            For left subtree (4):
                Both left and right are nullptr, so returns 0 for both.
                Therefore, depth is max(0, 0) + 1 = 1.
            For right subtree (5):
                Both left and right are nullptr, so returns 0 for both.
                Therefore, depth is max(0, 0) + 1 = 1.
            Therefore, depth for node 2 is max(1, 1) + 1 = 2.
        For right subtree (3):
            Both left and right are nullptr, so returns 0 for both.
            Therefore, depth is max(0, 0) + 1 = 1.
        Therefore, depth for root (1) is max(2, 1) + 1 = 3.

The maximum depth of the tree is 3, which is the correct answer.

The approach ensures that every node in the tree is visited and checked for its depth, making it a comprehensive solution.*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int FindHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
    //why are we adding 1 and taking the max? Because we are counting the edges, not the nodes. 
}

//implement the rest of the functions to create a binary search tree

int main(){
    return 0;
}