//Find min and max in binary search tree

#include <iostream>

using namespace std;

//in linked list we always track the head node, in binary tree we always track the root node

struct BstNode
{
    int data;
    BstNode* left; //left child
    BstNode* right; //right child
};
/*Iterative solution:
int FindMin(BstNode* root){
    this root is local to the function, so we can change it
    if(root == nullptr){ //if the tree is empty
        cout << "Error: Tree is empty\n"; //print error message
        return -1; //return -1
    }
    while(root->left != nullptr){ //while the left child is not null
        root = root->left; //set the pointer to the left child
    }
    return root->data; //return the data of the pointer. It will be the minimum value
}

int FindMax(BstNode* root){
    if(root == nullptr){
        cout<<"Error: Tree is empty\n";
        return -1;
    }

    while(root->right != nullptr){
        root = root -> right;
    }

    return root -> data;
}
*/
//Recursive solution:
int FindMin(BstNode* root){
    if(root == nullptr){ //if the tree is empty
        cout << "Error: Tree is empty\n"; //print error message
        return -1; //return -1
    }
    else if(root->left == nullptr){ //if the left child is null
        return root->data; //return the root node
    }
    return FindMin(root->left); //search the left child
    //We used recursion because we are searching the left child each time we call the function
}

int FindMax(BstNode* root){
    if(root == nullptr){
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->right == nullptr){
        return root->data;
    }
    return FindMax(root->right);
    //The logic of the recursive solution is, we are searching the right child each time we call the function
    //We are searching the right child until we reach the last right child
}

int main()
{
    return 0;
}