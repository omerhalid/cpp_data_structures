//reverse linked list using recursion
//omer halit cinar

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* head;

void Reverse(Node* p){

    if(p->next == nullptr){ //if p is the last node
        head = p; //make p the first node because it will be the last node after reversing
        return;
    }
    Reverse(p->next);
    Node* q = p->next; //q is the next node
    q->next = p; //make the next node point to the current node
    p->next = nullptr; //make the current node point to null
}