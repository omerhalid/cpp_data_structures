//stack implementation using linked list

//High level logic is that we will use a linked list to implement a stack
//We will use the head of the linked list as the top of the stack
//We will use the tail of the linked list as the bottom of the stack
//We will use the push and pop operations of the linked list to implement the push and pop operations of the stack

//advantages of using linked lists to implement stacks:
//1. we don't need to know the size of the stack beforehand
//2. we don't need to worry about stack overflow

//disadvantages of using linked lists to implement stacks:
//1. we need to use extra memory to store the pointers
//2. we can't do random access like we can do with arrays

//worst case time complexity for insert/delete at the end is O(n) where n is the size of the linked list
//worst case time complexity for insert/delete at the beginning is O(1)

//for simplicity we will call the head of the linked list as the top of the stack

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = nullptr; //top of the stack, initially empty

void Push(int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = top; //make the new node point to the current top node
    top = temp; //make the new node the top node
}

void Pop(){
    if(top == nullptr) return;

    Node* temp;

    temp = top; //make temp point to the top node
    top = top -> next; //make the next node the top node
    delete temp; //delete the old top node

}

bool isEmpty(){
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void printTop(){
    cout<<"The top:"<< top->data<<endl;
}

void Print(){
    Node* temp;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){

    Push(2);
    Push(4);
    Push(6);
    Pop();
    Push(8);
    printTop();
    Print();
    bool is_empty = isEmpty();
    cout << "Is the stack empty? " << (is_empty ? "Yes" : "No") << endl;
    
}