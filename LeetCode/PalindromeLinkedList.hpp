// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

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
    // bool isPalindrome(ListNode* head) {
    //     if(!head || !(head->next))
    //         return true;
    //     ListNode * slow = head, *fast = head;
    //     stack<int> s;
    //     s.push(head->val);
    //     //fast and slow move together
    //     while(fast->next && fast->next->next)
    //     {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //         s.push(slow->val);
    //     }
    //     //if there odd numbers nodes in list, pop out the center one
    //     if(!fast->next) s.pop();
    //     while(slow->next)
    //     {
    //         slow = slow->next;
    //         int temp = s.top();
    //         s.pop();
    //         if(slow->val != temp) return false;
    //     }
    //     return true;
    // }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !(head->next))
            return true;
        ListNode * slow = head, *fast = head;
        
        //fast and slow move together
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse linked list
        ListNode *pre = head, *last = slow->next;
        while(last->next)
        {
            ListNode* temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        //compare
        while(slow->next)
        {
            slow = slow->next;
            if(slow->val != pre->val) return false;
            pre = pre->next;
        }
        return true;
    }
    
};