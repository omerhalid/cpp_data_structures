//Queue implementation using linked list
//*****************************************************************************

//advantages of linked list implementation over array implementation:
//1. we don't need to know the size of the queue beforehand
//2. we don't need to shift the elements when we dequeue
//3. we can use the memory efficiently

//disadvantages of linked list implementation over array implementation:
//1. we need to allocate memory for each node
//2. we need to free the memory when we dequeue
//3. we need to handle the case when the queue is empty

//time complexity must be O(1) for enqueue and dequeue
//but how to achieve O(1) for dequeue?
//we can use a tail pointer to point to the last node of the queue
//we can use a head pointer to point to the first node of the queue

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

//initialize two pointers to point to the first and last node of the queue
Node *front = nullptr; 
Node *rear = nullptr;

void Enqueue(int x){
    Node *temp = new Node;
    temp->data = x;//set the data of temp to x
    temp->next = nullptr;//set the next of temp to nullptr
    if(front == nullptr && rear == nullptr){//if the queue is empty
        front = rear = temp;//set both front and rear to temp
        return;
    }
    rear->next = temp;//set the next of rear to temp. Why? because we want to add the new node to the end of the queue
    rear = temp; //set rear to temp. Why? because we want rear to point to the last node of the queue
}

void Dequeue(){
    Node *temp = front;//create a temporary pointer to point to the first node of the queue
    if(front == nullptr){//if the queue is empty
        cout << "Queue is empty" << endl;
        return;
    }
    if(front == rear){//if there is only one node in the queue
        front = rear = nullptr;//set both front and rear to nullptr
    }
    else{
        front = front->next;//set front to the next of front. Why? because we want front to point to the second node of the queue
    }
    delete temp;//free the memory of temp
}

void Print(){
    Node *temp = front;//create a temporary pointer to point to the first node of the queue
    while(temp != nullptr){//while temp is not equal to nullptr
        cout << temp->data << " ";//print the data of temp
        temp = temp->next;//set temp to the next of temp. Why? because we want to move to the next node of the queue
    }
    cout << endl;
}

void Front(){
    if(front == nullptr){//if the queue is empty
        cout << "Queue is empty" << endl;
        return;
    }
    cout << front->data << endl;//print the data of front
}

void isEmpty(){
    if(front == nullptr && rear == nullptr){//if the queue is empty
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }
}

int main(){
    
        Enqueue(2); //Queue: 2
        Print(); 
        isEmpty();
        Enqueue(4); //Queue: 2, 4
        Print(); 
        Enqueue(6); //Queue: 2, 4, 6
        Enqueue(8); //Queue: 2, 4, 6, 8
        Print();
        Dequeue(); //Queue: 4, 6, 8
        Print();
}