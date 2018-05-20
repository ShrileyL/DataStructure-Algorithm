// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you implement both?

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
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next==NULL )
//             return head;
        
//         ListNode* p = head->next;
//         ListNode* res = head;
//         while(p)
//         {
//             head->next = p->next;
//             p->next = res;
//             res = p;
            
//             p = head->next;
//         }
//         return res;
//     }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL )
            return head;
        
        ListNode* pre=NULL, *cur = head, *next = NULL;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};