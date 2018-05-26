#include "linkedlist.h"

// This function prints contents of linked list starting from 
// the given node
void printList(struct Node *n)
{
  while (n != NULL)
  {
     printf(" %d ", n->data);
     n = n->next;
  }
  cout << endl;
}

void push(Node **head_ref, int new_data)
{
	//1.allocate node
	Node *new_node = new Node(new_data);

	//2.make next node to head
	new_node->next = (*head_ref);

	//3.move the head to point to the new node
	(*head_ref) = new_node;
};

void insertafter(Node* prev, int new_data)
{
	if(prev == NULL){return;}

	Node *new_node = new Node(new_data);

	new_node->next = prev->next;

	prev->next = new_node;
};

void append(Node **head_ref,int new_data)
{
	Node *new_node = new Node(new_data);

	Node* last = *head_ref;

	//if linked list is empty
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while(last->next)
		last = last->next;

	last->next = new_node;
	return;
};

Node* reverselist(Node *head)
{
	if(head == NULL)return head;

	Node *prev = NULL, *cur = head, *next = NULL;

	while(cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

Node* reverseBetween(Node* head, int m, int n)
{
	if(head == NULL || head->next == NULL)
		return head;

	int k = n-m+1;

	Node* f = new Node(0);
	f->next = head;

	Node *p = f, *c = head;
	while(m > 1)
	{
		p = c;
		c = c->next;
		m--;
	}

	Node *prev = NULL,*cur = c,*next = NULL;
	while(k>0)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		k--;
	}

	//relink
	p->next = prev;
	c->next = cur;

	return f->next;
}