//implementation of stacks

//we can implement stacs using:
//1. arrays
//2. linked lists

//stacks are used to store data in a LIFO manner

//stacks are used in:
//1. undo mechanisms
//2. backtracking
//3. function calls
//4. expression evaluation and syntax parsing
//5. memory management

//stacks have two main operations:
//1. push: adds an item to the stack
//2. pop: removes the top item from the stack

//stacks have two more operations:
//1. peek: returns the top item from the stack without removing it
//2. isEmpty: returns true if the stack is empty

//in this cpp we will implement stacks using arrays

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 101

int A[MAX_SIZE]; //array to store the stack

int top = -1; //variable to mark the top of the stack

//if overflow occurs;
//create a new array with double the size of the original array --> cost is O(n) where n is the size of the array 
void push(int x){
    if(top == MAX_SIZE-1){
        cout << "Error: stack overflow" << endl;
        return;
    }
    top ++;
    A[top] = x;
    //A[++top] = x; //this is the same as the two lines above, pre-incrementing top 
}

void pop(){
    if(top == -1){
        cout << "Error: no element to pop" << endl;
        return;
    }
    top --;
}

int Top(){
    return A[top];
}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

void Print(){
    cout << "Stack: ";
    for(int i = 0; i <= top; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    push(2);
    push(3);
    push(4);

    Print();

    pop();

    Print();

}