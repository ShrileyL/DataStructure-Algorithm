// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = head, *fast = head;
        
        int count = 0;
        bool flag = false;
        
        //fast is always n ahead with prev
        // while(i++ <= n)
        // {
        //     if(fast->next!=NULL)
        //         fast = fast->next;
        //     else//remove 1st node in list
        //         flag = true;
        // }
        
        
        while(fast != NULL)
        {
            if(count <= n )
            {
                fast = fast->next;
                count++;
            }
            else//prev and fast move together
            {
                fast = fast->next;
                prev = prev->next; 
            }
            
        }
        
        if(count <= n)
            head = head->next;
        else
            prev->next = prev->next->next;
        
        
        return head;
    }
};