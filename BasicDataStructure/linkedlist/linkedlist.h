#ifndef LINKEDLIST
#define LINKEDLIST 

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// A linked list node
struct Node
{
  int data;
  struct Node *next;

  Node(int val):data(val),next(NULL){};
};

void printList(struct Node *n);

void push(Node *head, int new_data);

void insertafter(Node* prev, int new_data);

void append(Node **head_ref,int new_data);

Node* reverselist(Node *head);

Node* reverseBetween(Node* head, int m, int n);

#endif
