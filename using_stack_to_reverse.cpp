//Problem: Reverse a string using stack

#include <iostream>
#include <cstring>
#include <stack> //we will use buildin stack from STL instead of implementing our own stack 

using namespace std;
/*
class Stack{
    private:
        int top;
        char A[101];
    public:
        void Push(int x);
        void Pop();
        bool isEmpty();
        int Top();
};*/

void Reverse(char *C, int n){
    //  Stack S;
    stack<char> S; //stack from STL
    for(int i = 0; i < n; i++){
        S.push(C[i]);
    }
    //whats happening here is that we are pushing the characters of the string into the stack
    for(int i = 0; i < n; i++){
        C[i] = S.top(); //overwrite the character at index i
        S.pop(); //perform pop
    }
    //time complexity: O(n)
    //space complexity: O(n) 
}

int main(){

    char C[51];
    cout<<"Enter a string: ";
    cin>>C;
    Reverse(C, strlen(C));
    cout<<"Output: "<<C<<endl;

    return 0; 
}