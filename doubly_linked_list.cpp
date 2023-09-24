//doubly linked list implementation

//Advantages: can be traversed in both directions
//Disadvantages: takes more memory than singly linked list

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct Node* head; //global variable

struct Node* GetNewNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;//because it will be the first node
    newNode->prev = nullptr;//because it will be the first node
    return newNode;
}

void InserAtHead(int x){
    
    Node* newNode = GetNewNode(x);
    if(head == nullptr){//if the list is empty
        head = newNode;//make the new node the first node because it is the only node
        return;
    }
    head->prev = newNode;//make the previous of the current first node point to the new node
    newNode->next = head;//make the next of the new node point to the current first node
    head = newNode;//make the new node the first node
}

void InsertAtTail(int x){
    
    Node* newNode = GetNewNode(x);
    if(head == nullptr){//if the list is empty
        head = newNode;//make the new node the first node because it is the only node
        return;
    }
    Node* temp = head;//temp is a pointer to traverse the list
    while(temp->next != nullptr){//traversing the list until the last node
        temp = temp->next;
    }
    temp->next = newNode;//make the next of the last node point to the new node
    newNode->prev = temp;//make the previous of the new node point to the last node
}

void Print(){
    Node* temp = head;
    cout << "Forward: ";
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint(){
    Node* temp = head;
    if(temp == nullptr) return; //empty list, exit
    //going to last node
    while(temp->next != nullptr){
        temp = temp->next;
    }
    //traversing backward using prev pointer
    cout << "Reverse: ";
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main(){

    head = nullptr; //empty list
    InserAtHead(2); Print(); ReversePrint();
    InserAtHead(4); Print(); ReversePrint();
    InserAtHead(6); Print(); ReversePrint();
    InserAtHead(8); Print(); ReversePrint();
    InserAtHead(10); Print(); ReversePrint();
    InsertAtTail(12); Print(); ReversePrint();
    InsertAtTail(14); Print(); ReversePrint();

    return 0;
}
