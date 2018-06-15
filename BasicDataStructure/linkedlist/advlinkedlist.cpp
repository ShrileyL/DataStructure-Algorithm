#include "linkedlist.h"

Node* deleteDuplicates(Node* head) 
{
    if(head==NULL) return head;
        
    Node *p = head;
    while(p!=NULL && p->next!=NULL)
    {
        while(p!=NULL && p->next != NULL && p->data == p->next->data)
        {
            //delete duplicate node
            p->next = p->next->next;
        }
        
        p = p->next;
    }
    return head;
};

Node* insertionSortList(Node* head)
{
	Node *cur=head, *next = NULL;
	Node *dummy = new Node(0);

	while(cur != NULL)
	{
		next = cur->next;
		Node *p = dummy;
		//travel to find the previous position to insert node
		while(p->next!=NULL && p->next->data < cur->data)
			p = p->next;

		//insert cur node to p->next
		cur->next = p->next;
		p->next = cur;
		cur = next;
	}

	return dummy->next;
}