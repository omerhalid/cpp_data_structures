//Linked List:
//A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.

LinkedList:
    
    Node: 
        - Contains data (could be of any type: integer, string, etc.)
        - Pointer/reference to the next node in the list (or null if it's the last node)

    Operations:

    1. Initialization:
        - Start with an empty list (i.e., head pointer/reference is null)

    2. Append (insert at the end):
        - If list is empty, create a new node and make the head point to it
        - Else, traverse the list to find the last node and make its next pointer/reference point to the new node

    3. Prepend (insert at the beginning):
        - Create a new node
        - Point the new node's next to the current head
        - Update the head to point to the new node

    4. Delete (by value):
        - If list is empty, return
        - If head node has the value, update head to its next pointer/reference
        - Else, traverse the list to find the node before the one to be deleted and update its next pointer/reference to skip the node to be deleted

    5. Display:
        - Start from the head and traverse the list
        - For each node, print its value

    6. (Optional) Search:
        - Traverse the list from the head
        - For each node, if its value matches the searched value, return the node (or true). If end of list is reached without finding, return null (or false)

Usage:

1. Create an empty linked list
2. Perform operations like append, prepend, delete, etc.
3. Display or search as needed

