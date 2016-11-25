/**************************************************
 * Key Points and Tips
 * 
 * #1 remeber to initialize pointer
 * #1.1 TNode
 *
 * Remark:  
 *
 * 2016/11/25 Shirley test
 *************************************************/

#include <iostream>
#include <stdio.h>
//#include 'malloc.h'
using namespace std;

struct Tag_Node
{
    struct Tag_Node* left;
    struct Tag_Node* right;
    int value;
};

typedef struct Tag_Node TNode;

TNode* root = NULL;

void append(int N);
void print();

int main(int argc, char const *argv[])
{
    append(63);
    append(45);
    append(32);
    append(77);
    append(96);
    append(21);
    append(17);
    std::cout << "head: " << root->value <<std::endl;
    print();
    return 0;
}

void append(int N)
{
    TNode* NewNode = (TNode*)malloc(sizeof(TNode));
    NewNode->value = N;
    NewNode->left = NULL;//initialize left
    NewNode->right = NULL;//initialize right
    
    if (root == NULL)
    {
        root = NewNode;
        return;
    }
    else
    {
        TNode* temp;
        temp = root;
        
        while ((N>=temp->value && temp ->left!= NULL)||(N < temp->value && temp->right != NULL))
        {
            while (N>=temp->value && temp ->left!= NULL)
                temp = temp ->left;
            while (N < temp->value && temp->right != NULL)
                temp = temp ->right;
        }
        if (N >= temp -> value)
        {
            temp->left = NewNode;
            NewNode->right = temp;//double-linked list
        }
        else
        {
            temp ->right = NewNode;
            NewNode->left = temp;//double-linked list
        }
        return;
    }
}

void print()
{
    TNode* leftside = NULL;
    
    if (root == NULL) {
        std::cout << "There is not any element."<< std::endl;
        return;
    }
    leftside = root->left;
    while (1)
    {
        if (leftside->left == NULL) {
            break;
        }
        leftside = leftside->left;
    }
    
    while (leftside != NULL) {
        std::cout << leftside ->value<< " ";
        leftside = leftside->right;
    }
}