//omer halit cinar
//linked list using recursion

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

//It is because of the stack that we can use recursion to print the linked list in reverse order. 
//The recursive call is made first, and then the value in the node is printed. 
//As the recursive calls are made, the nodes are pushed onto the stack. 
//When the base case is reached, the nodes are popped off the stack and the values are printed. 
//This is the reason why the linked list is printed in reverse order.

void ReversePrint(struct Node* p){
    if (p == nullptr) return; //exit condition
    //cout<<p->data<<" "; //first print the value in the node
    //Print(p->next); //recursively call the function with the next node
    //if we change the order of the above two lines, we will get the reverse of the linked list. Why? Because the recursive call is made before printing the value in the node.
    ReversePrint(p->next);
    cout<<p->data<<" ";
}

struct Node* Insert(Node* head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr) head = temp;
    else{
        Node* temp1 = head;//temp1 is a pointer to the head node
        while (temp1->next != nullptr) temp1 = temp1->next;//traverse the list until the last node
        temp1->next = temp;//link the last node to the new node
    }
    return head;
}

int main(){

    struct Node* head = nullptr; //local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    ReversePrint(head);

}