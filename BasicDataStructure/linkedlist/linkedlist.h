#ifndef LINKEDLIST
#define LINKEDLIST 

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// A linked list node
struct Node
{
  int data;
  struct Node *next;

  Node(int val):data(val),next(NULL){};
};

//help print method
void printList(struct Node *n);

//basic methods
void push(Node *head, int new_data);

void insertafter(Node* prev, int new_data);

void append(Node **head_ref,int new_data);

void deleteNode(Node* node);

Node* reverselist(Node *head);

Node* reverseBetween(Node* head, int m, int n);

//advanced linked list methods
Node* insertionSortList(Node* head);

Node* deleteDuplicates(Node* head);

#endif
