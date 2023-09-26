//Problem: Reverse a linked list using stack

//Iterative solution:
//Time complexity: O(n)
//Space complexity: O(1)

//Recursive solution: (Implicit stack)
//Time complexity: O(n)
//Space complexity: O(n)
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;       // Value held by the node
    Node* next;     // Pointer to the next node in the list
};

// Pointer to the head of the list
Node* head = nullptr;

// Function to insert a new node at the end of the linked list
void insert(int data) {
    Node* temp = new Node();   // Create a new node
    temp->data = data;
    temp->next = nullptr;

    if(head == nullptr) {      // If list is empty, make the new node the head
        head = temp;
        return;
    }

    Node* last = head;         // Traverse to the end of the list
    while(last->next != nullptr) {
        last = last->next;
    }

    last->next = temp;         // Insert the new node at the end
}

// Function to print the linked list
void print() {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list using a stack
void Reverse() {
    if(head == nullptr) return;  // If list is empty, just return
    
    stack<Node*> S;
    Node* temp = head;

    // Push all nodes onto the stack
    while(temp != nullptr) {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();         // Start from the last node
    head = temp;            // Make it the new head of the list
    S.pop();                //why are we popping here? because we dont want to point to the same node again
    /*We're popping here because we've just processed the top of the stack (the last node of the original list). 
    We've already made this node the head of our new list. 
    Now, the next node to process will be the second-last node from the original list, and so on.
    If we didn't pop here, then during the next iteration of our loop, we would be pointing the "next" of the new head node back to itself, 
    which would be incorrect.*/

    // Reconstruct the list in reverse order using the stack
    while(!S.empty()) {
        temp->next = S.top();   // The next node is the one at the top of the stack
        S.pop();
        temp = temp->next;      //the logic here is that we are moving the temp pointer to the next node
    }

    temp->next = nullptr;   // Ensure the last node points to nullptr
}

int main() {
    // Build the linked list
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Display the original list
    cout << "Original List: ";
    print();

    // Reverse the list
    Reverse();

    // Display the reversed list
    cout << "Reversed List: ";
    print();

    return 0;
}
