// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        if(headA == NULL || headB == NULL)
        return NULL;
        
        unordered_set<ListNode*> s;
        //travel 1st linked list and add to the hash table
        while(p1 != NULL)
        {
            s.insert(p1);
            p1 = p1->next;
        }
        
        //travel 2nd list, find if there is a intersection
        while(p2 != NULL)
        {
            if(s.find(p2) != s.end())
                return p2;
            
            p2 = p2->next;
        }
        
        return NULL;
    }
    /****************   method 2  *****************/
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         ListNode *cur1 = headA, *cur2 = headB;
//         while(cur1 != cur2)
//         {
//             cur1 = cur1? cur1->next:headA;
//             cur2 = cur2? cur2->next:headB;
//         }
        
//         return cur1;
//     }
};