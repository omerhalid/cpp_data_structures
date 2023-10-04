//Problem statement link: https://leetcode.com/problems/binary-tree-inorder-traversal/

//Tree is not a linear data structure, so we can't traverse it in a linear way.
//we can have more than one possible directions to traverse the tree.

//Tree traversal: visiting each node in the tree exactly once.

//BFS: breadth first search: level order traversal
//DFS: depth first search: preorder, inorder, postorder traversal

//Preorder traversal: root, left, right
//Inorder traversal: left, root, right (gives sorted order for BST)
//Postorder traversal: left, right, root

//Level-order implementation using queue:
//Time complexity: O(n)
//Space complexity: O(n)

//Space complexity means the extra space used by the algorithm, not including the space taken up by the inputs.
//Time complexity means the number of operations the algorithm performs on the inputs.

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    char data; 
    Node *left;
    Node *right;
};

void LevelOrder(Node *root)
{
    if(root == NULL)
        return;
    
    queue<Node*> Q; //creating an empty queue
    Q.push(root);

    //while there is at least one discovered node
    while(!Q.empty())
    {
        Node *current = Q.front(); //current will point to the front element of the queue
        Q.pop(); //removing the element at front, why? because we have already stored it in current

        cout << current->data << " ";

        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
    }
}

int main()
{
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

    LevelOrder(root);

    return 0;
}