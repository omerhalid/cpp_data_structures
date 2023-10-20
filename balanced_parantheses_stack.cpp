

//test
//Explonation of the task: https://www.hackerrank.com/challenges/balanced-brackets/problem

// Logical approach:
// 1. We will use stack to solve this problem.
// 2. We will push the opening brackets into the stack.
// 3. When we encounter a closing bracket, we will check if the top of the stack is the corresponding opening bracket.
// 4. If it is, we will pop the top of the stack and continue processing the string.
// 5. If it is not, we will return false.
// 6. If the stack is empty at the end, we will return true. Otherwise, we will return false.

//input: [({})]
//output: true

//input: [({)}]
//output: false

//Last unclosed bracket should be closed first

#include <iostream>
#include <stack>

using namespace std;

//char opening_char [] = {'(', '{', '['};
//char closing_char [] = {')', ']', '}'};

bool isBalanced(string expression) {
    stack<char> S;
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){ //if the character is an opening bracket, push it into the stack
            S.push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){//if the character is a closing bracket, check if the top of the stack is the corresponding opening bracket
            if(S.empty()){//if the stack is empty, return false
                return false;
            }
            //if the stack is not empty, check if the top of the stack is the corresponding opening bracket
            //if it is, pop the top of the stack and continue processing the string
            else if(expression[i] == ')' && S.top() == '('){
                S.pop();
            }
            else if(expression[i] == '}' && S.top() == '{'){
                S.pop();
            }
            else if(expression[i] == ']' && S.top() == '['){
                S.pop();
            }
            else{
                return false;
            }
        }
    }
    if(S.empty()){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    string expression;
    cout<<"Enter an expression: ";
    cin>>expression;
    if(isBalanced(expression)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not balanced"<<endl;
    }

    return 0;

}