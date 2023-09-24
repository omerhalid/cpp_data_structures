//omer halit cinar
//reverse the linked list

struct Node{
    int data;
    Node* next;
};

Node* head;

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