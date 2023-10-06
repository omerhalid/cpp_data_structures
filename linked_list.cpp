//reverse the linked list:
//https://www.enjoyalgorithms.com/blog/reverse-linked-list

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr; //global init.

void InsertBeginning(int x){

    Node* temp = new Node();

    temp -> data = x;

    temp -> next = head;

    head = temp;
}

void InsertNthPositon(int x, int n){
    //x is the data and n is the position

    Node* new_data = new Node();

    new_data -> data = x;
    new_data -> next = nullptr;

    if(n == 1){
        InsertBeginning(x); //is this ok? I guess, yeah
        return;
    }

    Node* temp = new Node();
    temp = head;

    //Traverse the list
    for(int i=0; i< n-2 ; i++){
        temp = temp -> next; //we cme to the n-1 position
    }

    new_data -> next = temp -> next;

    temp -> next = new_data;

}

void Print(){

    Node* temp = new Node();
    temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

//delete the head node
void DeleteHead()
{
    if (head == nullptr) return;

    Node* temp = head;

    head = head -> next;

    delete temp;

}

//delete the tail node
void DeleteTail()
{
    //we will use two pointer method

    if(!head) return;
    if(head -> next == nullptr)
    {
        DeleteHead();
        return;
    }

    Node* ptemp = head;
    Node* temp = head -> next; //it needs to be one step further than ptemp
    

    //traverse the list
    while(temp -> next != NULL)
    {
        ptemp = ptemp ->next;
        temp = temp-> next;
    }
    //now i am at the last node
    ptemp -> next = nullptr;

    delete temp;

}

//delete nth element
void DeleteNthNode(int n){

    if(head == nullptr) return;
    if(n == 1){
        DeleteHead();
        return;
    }

    Node* temp = head;

    //traverse the list
    for(int i=0; i<n-2; i++){
        temp = temp -> next; //we found the n-1 node
        //check if n is greater than the length of the list
        if(temp == nullptr){
            cout<<"Position out of bounds!"<<endl;
        }
    }

    Node* toBeDeleted = temp -> next; //we are putting the node we want to delete into a new temp node
    if (toBeDeleted == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    temp -> next = toBeDeleted -> next;

    delete toBeDeleted;
    
}

void DeleteNthAtTheEnd(int n){
    //we can work with the offset
    
    Node* dummy = new Node();

    dummy->data = NULL;
    dummy->next = head;
    
    Node* first = head;
    Node* last = dummy;

    for(int i=0; i<n; i++){
        first = first -> next;
    }

    while(first != nullptr){
        first = first->next;
        last = last ->next;
    }

    //last is the node we want to delete

    Node* nodeToDelete = last ->next;

    last -> next = last -> next -> next;

    delete nodeToDelete;
    delete dummy;
    

}

void Inverse()
{
    //come back to this and study it again. 

    //2 options:
    // -Recursive
    // -Iterative

    //We will iterative method with 3 pointers

    Node* current = head;
    Node* prev = nullptr;
    Node* forw = nullptr;

    while(current != nullptr){
        forw = current ->next; 
        current -> next = prev;
        prev = current; //shift the prev
        current = forw; //shift the current

    }

    head = prev; // update the head pointer

}

int main(){
    InsertBeginning(5);
    InsertNthPositon(1, 2);
    
    InsertNthPositon(2, 3);
    
    InsertNthPositon(3, 4);
    
    InsertNthPositon(4, 5);
    InsertNthPositon(5, 6);
    InsertNthPositon(6, 7);
    InsertNthPositon(7, 8);

    Print();

    DeleteHead();
    Print();

    DeleteTail();
    Print();

    DeleteNthNode(3);
    Print();

    DeleteNthNode(4);
    Print();

    Inverse();
    Print();

    DeleteNthAtTheEnd(2);
    Print();
}