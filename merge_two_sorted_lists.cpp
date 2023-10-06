
/*    Initialize:
        Create a dummy node to act as the starting point of the merged list.
        Create a current pointer and set it to point to dummy.

    Merge Loop:
        While both list1 and list2 have nodes left:
            Compare the values at the heads of list1 and list2.
            Whichever value is smaller, attach that node to the next of current.
            Move the chosen list's pointer to its next node.
            Advance the current pointer to its next node.

    Attach Remaining Nodes:
        If list1 has nodes left, attach it to the next of current.
        If list2 has nodes left, attach it to the next of current.

    Return the Merged List:
        Return dummy.next as the starting node of the merged list, skipping the dummy node.

Remember, the idea behind using the dummy node is to simplify the process by giving us an initial node to start the merged list without
any special checks. The current pointer helps us keep track of the last node in our merged list, 
making it easy to append the next node from either list1 or list2.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy(0);
        ListNode* current = &dummy;

        while(list1 != nullptr && list2 != nullptr)
        {

            if((list1->val) <= (list2->val))
            {
                current -> next = list1;
                list1 = list1 -> next;
            }
            else
            {
                current -> next = list2;
                list2 = list2 -> next;
            }

            current = current->next;
        }

        if(list1 != nullptr){
            current -> next = list1;
        }
        if(list2 != nullptr){
            current -> next = list2;
        }

        return dummy.next;
    }  
};