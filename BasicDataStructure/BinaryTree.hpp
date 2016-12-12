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
    TreeNode<T> *root;
    int size;
    void inorder(TreeNode<T> *root);
    void preorder(TreeNode<T> *root);
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
    void getroot() 
    {
        TreeNode<T> *p = root;
        for (int i = 0; i < size; ++i) {
            cout << p->element << endl;
            if(p->left != NULL)
            p = p -> left;
            else if(p->right != NULL)
                p = p -> right;
            else
                cout << " wrong" << endl;
        }
    }
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
    inorder(root);
}

template <typename T>
void BinaryTree<T>::inorder(TreeNode<T> *root)
{
    if(root == NULL)
    return;
    
    inorder(root->left);
    cout << root->element << " ";
    inorder(root->right);
}

template <typename T>
void BinaryTree<T>::preorder()//deep-first traversal
{
    preorder(root);
}

template <typename T>
void BinaryTree<T>::preorder(TreeNode<T> *root)
{
    if(root == NULL)
        return;
    
    cout << root->element << " ";
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void BinaryTree<T>::postorder()
{
    postorder(root);
}

template <typename T>
void BinaryTree<T>::postorder(TreeNode<T> *root)
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->element << " ";
}

#endif /* Node2_hpp */
