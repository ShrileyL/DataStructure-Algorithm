//
//  BinaryTreeSearchIterative.hpp
//
//  Iterative instead of recursion
//  DFS Deep-first search using stack
//  BFS Breath-first search using queue
//
//  Created by KevinLiu on 16/12/12.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef BinaryTreeSearchIterative_hpp
#define BinaryTreeSearchIterative_hpp

#include <stdio.h>

#include <iostream>
#include <stdexcept>
#include <stack>//include stack

using namespace std;

template <typename T>
class TreeNode {
    
public:
    T element;
    TreeNode<T> *left;
    TreeNode<T> *right;
    
    TreeNode():left(NULL),right(NULL){};
    
    TreeNode(const T ele)
    {
        element = ele;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinaryTree {
    TreeNode<T> *root;
    int size;
    void inorder(TreeNode<T> *root);
    void preorder(TreeNode<T> *root);//deep-first traversal
    void postorder(TreeNode<T> *root);
public:
    BinaryTree();
    BinaryTree(T arr[], int arraysize);
    bool insert(const T element);
    //    void print();
    void inorder();
    void preorder();
    void postorder();
    
    int getsize() const;
    
};

template <typename T>
BinaryTree<T>::BinaryTree():root(NULL),size(0){};

template <typename T>
BinaryTree<T>::BinaryTree(T arr[], int arraysize)
{
    size = 0;
    root = NULL;
    for (int i = 0; i < arraysize; ++i)
    {
        insert(arr[i]);
    }
}

template <typename T>
int BinaryTree<T>::getsize() const
{
    return size;
}

template <typename T>
bool BinaryTree<T>::insert(const T ele)
{
    //if binary tree is empty
    //create a root node for the new element
    if (root == NULL)
        root = new TreeNode<T>(ele);
    else
    {
        //locate the parent node
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        
        //find the position to be insert
        while (current != NULL)
        {
            if (ele <= current->element )
            {
                parent = current;
                current = current->left;
            }
            else if(ele > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                return false;
        }
        
        //create the new node and attach it to the parent
        if (ele < parent->element)
            parent->left = new TreeNode<T>(ele);
        else
            parent->right = new TreeNode<T>(ele);
    }
    ++size;
    return true;
}

// iterative solution using stack
template <typename T>
void BinaryTree<T>::inorder()
{
//    stack<TreeNode<T>*> s;
//    if(root == NULL)
//        return;
//    
//    TreeNode<T> *current = root;
//    bool done = false;
//    
//    while (!done)
//    {
//        if(current)
//        {
//            s.push(current);
//            current = current->left;
//        }
//        else
//        {
//            if(s.empty())
//                done = true;
//            else
//            {
//                current = s.top();
//                s.pop();
//                cout << current->element << " ";
//                current = current->right;
//            }
//        }
//    }
    
    stack<TreeNode<T>*> s;
    TreeNode<T> *current = root;
    
    while (!s.empty()||current)
    {
        if(current)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
                current = s.top();
                s.pop();
                cout << current->element << " ";
                current = current->right;
        }
    }
}


template <typename T>
void BinaryTree<T>::preorder()
{
        // Base Case
    if (root == NULL)
       return;

    // Create an empty stack and push root to it
    stack<TreeNode<T>*> s;
    TreeNode<T> *current = root;
    s.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (!s.empty())
    {
        // Pop the top item from stack and print it
        current = s.top();
        s.pop();
        cout << current->element << " ";
        // Push right and left children of the popped node to stack
        if(current->right)
            s.push(current->right);
        if(current->left)
            s.push(current->left);
    }
}

template <typename T>
void BinaryTree<T>::postorder()
{
    stack<TreeNode<T>*> s;
    s.push(root);
    TreeNode<T> *curr= s.top();
    TreeNode<T> *prev = NULL;

    while (!s.empty()) 
   {
        TreeNode<T>* curr = s.top();
    // we are traversing down the tree
        if (!prev || prev->left == curr || prev->right == curr) 
        {
            if (curr->left) 
                s.push(curr->left);
            else if (curr->right) 
                s.push(curr->right);
            else 
            {
                cout << curr->element << " ";
                s.pop();
            }
        } 
    // we are traversing up the tree from the left
        else if (curr->left == prev) 
        {
            if (curr->right) 
                s.push(curr->right);
            else 
            {
                cout << curr->element << " ";
                s.pop();
            }
        }
    // we are traversing up the tree from the right
        else if (curr->right == prev) 
        {
            cout << curr->element << " ";
            s.pop();
        }

    prev = curr;  // record previously traversed node
  }
}

//more effecient post-order traversal
template <typename T>
void BinaryTree<T>::postorder()
{
        if (!root) return;
    stack<TreeNode<T>*> s;
    s.push(root);
    TreeNode<T>* prev = NULL;
    while (!s.empty())
    {
        TreeNode<T>* curr = s.top();
        if (!prev || prev->left == curr || prev->right == curr)
        {
            if (curr->left)
                s.push(curr->left);
            else if (curr->right)
                s.push(curr->right);
        }
        else if (curr->left == prev)
        {
            if (curr->right)
                s.push(curr->right);
        }
        else
        {
            cout << curr->element << " ";
            s.pop();
        }
        prev = curr;
    }
}
#endif /* BinaryTreeSearchIterative_hpp */
