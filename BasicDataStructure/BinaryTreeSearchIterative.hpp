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
#include <stack>
//#include "StackWIthLinkedList.hpp"

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

template <typename T>
void BinaryTree<T>::inorder()
{
    stack<TreeNode<T>*> s;
    if(root == NULL)
        return;
    
    TreeNode<T> *current = root;
    bool done = false;
    
    while (!done)
    {
        if(current)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            if(s.empty())
                done = true;
            else
            {
                current = s.top();
                s.pop();
                cout << current->element << " ";
                current = current->right;
            }
        }
    }
}


template <typename T>
void BinaryTree<T>::preorder()//deep-first traversal
{
   
}

template <typename T>
void BinaryTree<T>::postorder()
{
    
}


#endif /* BinaryTreeSearchIterative_hpp */
