// Program to create a simple linked 
// list with 3 nodes
#include "linkedlist.h"
#include <iostream>

using namespace std;

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    
    // // allocate 3 nodes in the heap  
    // head = (struct Node*)malloc(sizeof(struct Node)); 
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));
    //head = new Node(1);
    head->next = second; // Link first node with the second node
    
    //second = new Node(2);
    second->next = third; // Link second node with the third node
    
    //third = new Node(3);
    third->next = NULL;
    printList(head);

    append(&head,4);
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,2);
    append(&head,3);
    printList(head);

    // head = reverselist(head);
    // printList(head);

    head = reverseBetween(head,3,6);
    printList(head);


    //test for deleteNode
    deleteNode(head->next->next);
    printList(head);

    //sort
    insertionSortList(head);
    printList(head);

    head = deleteDuplicates(head);
    printList(head);
    return 0;
}