//binary tree implementation

//Binary search tree time complexity: (balanced tree)
//Insertion: O(log n)
//Deletion: O(log n)
//Search: O(log n)

//When to use binary tree?:
//When you want to search for an element in a sorted list  
//When you want to insert/delete an element in a sorted list
//When you want to find the minimum/maximum element in a sorted list

//What is a binary tree?:
//A binary tree is a tree data structure in which each node has at most two children, 
//which are referred to as the left child and the right child.
//left child <= parent < right child

//n -> n/2 -> n/4 -> n/8 -> ... -> 1 O(log n)

//High level logic for searching for an element in a binary search tree:
//1. Find the middle element of the array and make it the root
//2. Check if the middle element is equal to the element we are looking for
//3. If not, check if the element is less than the middle element
//4. If it is, search the left half of the array
//5. If not, search the right half of the array

//High level implementation:
//1. Create a node struct
//2. Create a binary search tree class
//3. Create a root node
//4. Create a function to insert a node
//5. Create a function to search for a node
//6. Create a function to delete a node
//7. Create a function to find the minimum node
//8. Create a function to find the maximum node
//9. Create a function to find the successor of a node
//10. Create a function to find the predecessor of a node
//11. Create a function to print the tree in order
//12. Create a function to print the tree pre order
//13. Create a function to print the tree post order

#include <iostream>

using namespace std;

//in linked list we always track the head node, in binary tree we always track the root node
//it is very similar to dubly linked list, because it has left and right child just like next and prev
struct BstNode
{
    int data;
    BstNode* left; //left child
    BstNode* right; //right child
};

BstNode* GetNewNode(int data){ //because we declared the pointer locally(in main), we need to return it in node type
    BstNode* newNode = new BstNode(); //create a new node
    newNode->data = data; //set the data (or(*newNode).data = data;))
    newNode->left = nullptr; //set the left child to null 
    newNode->right = nullptr; //set the right child to null
    return newNode; //return the new node
}

//We needed to use pointer to pointer(**) because we are changing the root node in the function and we want to keep the changes in the main function. 
//We are passing the address of the root node to the function. It is all because we initialized the root node in the main function and we want to keep the changes in the main function.
//If we didn't initialize the root node in the main function, we could have used pointer(*).
//It is an easier approach to declare the root node globally, so we don't have to use pointer to pointer.
BstNode* Insert(BstNode* root, int data){ 
    if(root == nullptr){ //if the tree is empty
        root = GetNewNode(data); //create a new node
        return root; //return the new node
    }
    else if(data <= root->data){ //if the data is less than the root node
        root->left = Insert(root->left, data); //create a new node and set it to the left child
    }
    else{ //if the data is greater than the root node
        root->right = GetNewNode(data); //create a new node and set it to the right child
    }
    return root; //return the root node

    //each time we call the function, we are creating a new node and setting it to the left or right child
}
//try to write the Insert function without recursion. You will need to use some temprorary pointers to keep track of the nodes and loops.

bool Search(BstNode* root, int data){
    if(root == nullptr){ //if the tree is empty
        return false; //return false
    }
    else if(root->data == data){ //if the root node is equal to the data
        return true; //return true
    }
    else if(data <= root->data){ //if the data is less than the root node
        return Search(root->left, data); //search the left child
    }
    else{ //if the data is greater than the root node
        return Search(root->right, data); //search the right child
    }
    //each time we call the function, we are searching the left or right child of the root node
}

int main()
{

    BstNode* root = nullptr; //empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int number;
    cout << "Enter number to be searched\n";
    cin >> number;
    if(Search(root, number) == true){
        cout << "Found\n";
    }
    else{
        cout << "Not Found\n";
    }

}