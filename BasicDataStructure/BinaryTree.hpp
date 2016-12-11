//
//  BinaryTree.hpp
//  test
//
//  Created by KevinLiu on 16/12/9.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class TreeNode {
    
public:
    T element;
    TreeNode<T> *left;
    TreeNode<T> *right;
    
    TreeNode():left(NULL),right(NULL){};
    
    TreeNode(T ele)
    {
        element = ele;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinaryTree {
    TreeNode<T> root;
    int size;
    
public:
    BinaryTree();
    BinaryTree(T *arr, int arraysize);
    bool insert(const T element);
//    void print();
    void inorder();// print
    void preorder();
    void postorder();
    int getsize() const;
};

template <typename T>
BinaryTree<T>::BinaryTree():root(NULL),size(0){};

template <typename T>
BinaryTree<T>::BinaryTree(T *arr, int arraysize)
{
    size = arraysize;
    root.element = *arr;
    for (int i = 0; i < arraysize; ++i)
    {
        insert(*(arr+i));
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
    if (size == 0)
    {
        root.element = ele;
        root.left = NULL;
        root.right = NULL;
        ++size;
        return true;
    }
    else
    {
        TreeNode<T> *p = &root;
        
        //find the position to be insert
        while (p != NULL)
        {
            if (ele <= p->element )
                p = p->left;
            else
                p = p->right;
        }
        
        p = new TreeNode<T>(ele);//create and insert the node
        
        return true;
    }
}

#endif /* Node2_hpp */
