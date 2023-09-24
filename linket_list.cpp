//omer halit cinar

#include <iostream>

using namespace std;

//implement basic linked list
//take screenshots from the youtube video

//create a node
struct Node
{
    int data; //data field
    Node* next; //link field
};

Node* head; //global variable

//insert a node at the beginning of the list
void Insert_beginning(int x)
{
    Node* temp = new Node(); //create a new node
    temp -> data = x; //set the data
    temp -> next = head; //set the link
    head = temp; //set the head to temp
}

//insert a node at the nth position
void Insert(int data, int n)
{
    Node* temp1 = new Node(); //create a new node
    temp1 -> data = data; //set the data
    temp1 -> next = NULL; //set the link to NULL
    if(n == 1){
        temp1 -> next = head;
        head = temp1;
        return ;
    }
    Node* temp2 = head; //create a new node
    for(int i = 0; i < n-2; i++)
    //why i < n-2? because we want to stop at the node before the nth node
    {
        temp2 = temp2 -> next; //traverse the list
    }
    temp1 -> next = temp2 -> next; //set the link of the new node to the link of the node before the nth node
    temp2 -> next = temp1; //set the link of the node before the nth node to the new node
}

void Print(Node* head)
{
    cout << "List is: ";
    //traverse the list
    while(head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

//reverse the linked list
void Reverse()
{
    Node* current; //current node 
    Node* prev; //previous node
    Node* next; //next node
    current = head;
    prev = nullptr;
    while(current != nullptr)
    {
        next = current -> next; //store the next node
        current -> next = prev; //reverse the link
        prev = current; //move prev one step forward
        current = next; //move current one step forward
    }
    head = prev; //set the head to last node
}

void Delete(int n){
    Node* temp1 = head;
    //if we want to delete the first node
    if(n == 1){
        head = temp1 ->next;
        delete temp1;
        return;
    }
    for(int i=0; i<n-2; i++){
        temp1 = temp1 -> next;
    }
    Node* temp2 = temp1 -> next; //nth node to be deleted
    temp1 -> next = temp2 -> next; //set the link of the node before the nth node to the link of the node after the nth node
    delete temp2; //delete the nth node
}

int main() {

    head = nullptr; 

    cout << "How many numbers?" << endl;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the number" << endl;
        cin >> x;
        cout << "Enter the position" << endl;
        int pos;
        cin >> pos;
        Insert(x, pos);
        Print(head);
    }
    cout << "Enter a position to delete" << endl;
    int del_pos;
    cin >> del_pos;
    Delete(del_pos);
    Print(head);
    cout<<"Do you want to reverse the list? (y/n)"<<endl;
    char ans;
    cin >> ans;
    if(ans == 'y'){
        Reverse();
        Print(head);
    }
    return 0;
}