//Queue ADT: array-based implementation
//************************************************************
//A list or collection with the restriction that insertion can be
//performed at one end (rear) and deletion can be performed at the other end (front)

//Operations:
//1. enqueue: insert an element at the rear of the queue (or Push)
//2. dequeue: delete an element from the front of the queue (or Pop)
//3. front: return the element at the front of the queue (or Peek)
//4. isEmpty: check if the queue is empty
//5. isFull: check if the queue is full (if the queue is implemented using an array)

//time complexity: O(1) for all operations (constant time)

//Visulaization:
//front -> 1 -> 2 -> 3 -> 4 -> 5 -> rear
//front -> 2 -> 3 -> 4 -> 5 -> rear
//front -> 3 -> 4 -> 5 -> rear

//Use cases:
//1. BFS (Breadth First Search) algorithm
//2. CPU scheduling
//3. Asynchronous data transfer
//4. IO Buffers

//we can implement a queue using an array or a linked list

//what happens when we fill up the array?
//we can use a circular array to solve this problem
//circular array: when we reach the end of the array, we can start from the beginning of the array.
//formula for circular array: (i + 1) % n. why mod n? because we want to wrap around the array
//current position = i
//next position = (i + 1) % n
//previous position = (i - 1 + n) % n
//example: n = 5, i = 4 (last position)
//next position = (4 + 1) % 5 = 0
//previous position = (4 - 1 + 5) % 5 = 3
//the queue: 1 -> 2 -> 3 -> 4 -> 5

#include <iostream>

using namespace std;

bool isFull(int front, int rear, int n){
    if((rear + 1) % n == front){//the logic is, if the next position of rear is equal to front, then the queue is full
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(int front, int rear){
    if(front == rear){
        //cout << "Queue is empty" << endl;
        return true;
    }
    else{
        //cout << "Queue is not empty" << endl;
        return false;
    }
}

void enqueue(int Q[], int &front, int &rear, int x, int n){
    if(isFull(front, rear, n)){
        cout << "Queue is full" << endl;
    }
    //handle the first element insertion
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        Q[rear] = x;
    }
    else{
        rear = (rear + 1) % n;
        Q[rear] = x;
    }
}

void dequeue(int Q[], int &front, int &rear, int n){
    if(isEmpty(front, rear)){
        cout << "Queue is empty" << endl;
        return;
    }
    else{
        front = (front + 1) % n;
    }
}

int Front(int Q[], int front){
    return Q[front];
}


void print(int Q[], int &front, int &rear, int n){
    //print the queue
    int i = front;
    while(true){
        cout<<Q[i]<<" ";
        if(i == rear){
            break;
        }
        i = (i + 1) % n;
    }
}

int main(){

    int front = -1;
    int rear = -1;

    int Q[5];

    enqueue(Q, front, rear, 1, 5);
    enqueue(Q, front, rear, 2, 5);
    enqueue(Q, front, rear, 3, 5);
    enqueue(Q, front, rear, 4, 5);

    dequeue(Q, front, rear, 5); //queue : 2 -> 3 -> 4
    dequeue(Q, front, rear, 5); //queue : 3 -> 4

    Front(Q, front);

    print(Q, front, rear, 5);

    isEmpty(front, rear);


}
