//
//  tree.cpp
//  test
//
//  Created by Shulin on 2018/5/31.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include "tree.hpp"
#include <iostream>
#include <stack>
#include <queue>

void insert(node* root,int val)
{
    node* tmp = new node(val);
    if(root == NULL)
    {
        root = tmp;
        return;
    }
    node* pre = root;
    while(true)
    {
    
        if(pre->data >= val)
        {
            if(pre->leftchild == NULL)
            {
                pre->leftchild = tmp;
                return;
            }
            pre = pre->leftchild;
        }
        else
        {
            if(pre->rightchild == NULL)
            {
                pre->rightchild = tmp;
                return;
            }
            pre = pre->rightchild;
        }
    }
};

//recursion
void preordertree(node* root)
{
    if(root == NULL) return;
    if(root!=NULL)
    {
    std::cout << root->data << " ";
    preordertree(root->leftchild);
    preordertree(root->rightchild);
    }
};
void postordertree(node* root)
{
    if(root == NULL) return;
    if(root)
    {
        postordertree(root->leftchild);
        postordertree(root->rightchild);
        std::cout << root->data << " ";
    }
}
void inordertree(node* root)
{
    if(root)
    {
        inordertree(root->leftchild);
        std::cout << root->data << " ";
        inordertree(root->rightchild);
    }
}

//iterative
void iterpreordertree(node* root)
{
    if(root == NULL) return;
    
    std::stack<node *> nstack;
    nstack.push(root);
    
    while(!nstack.empty())
    {
        node* tmp = nstack.top();
        std::cout << tmp->data << " ";
        nstack.pop();
        
        if(tmp->rightchild)
            nstack.push(tmp->rightchild);
        if (tmp->leftchild)
            nstack.push(tmp->leftchild);
    }
    std::cout << std::endl;
}
void iterpostordertree(node* root)
{
    if(root == NULL) return;
    
    std::stack<node *> first,second;
    first.push(root);
    
    while(!first.empty())
    {
        node* tmp = first.top();
        first.pop();
        second.push(tmp);
        
        if(tmp->leftchild)
            first.push(tmp->leftchild);
        if (tmp->rightchild)
            first.push(tmp->rightchild);
    }
    while (!second.empty()) {
        std::cout << second.top()->data << " ";
        second.pop();
    }
    std::cout << std::endl;
}
void iterinordertree(node* root)
{
    if(root == NULL) return;
    
    std::stack<node *> nstack;
    node* cur = root;
    
    while(cur || !nstack.empty())
    {
        //ifcur is not NULL
        if(cur)
        {
            nstack.push(cur);
            cur = cur->leftchild;
        }
        else{
            cur = nstack.top();
            std::cout << cur->data << " ";
            nstack.pop();
            
            cur = cur->rightchild;
        }
    }
    
    std::cout << std::endl;
}

//morris method
void morrisinorder(node* root)
{
    if(root == NULL) return;
    node* cur = root,*pre = NULL;
    
    while (cur)
    {
        //if left subtree does not exit
        if (cur->leftchild == NULL) {
            std::cout << cur->data << " ";
            cur = cur->rightchild;
        }
        //else find rightmost node of subtree, set its rightchild to cur
        else
        {
            pre = cur->leftchild;
            
            while (pre->rightchild!=NULL && pre->rightchild!=cur) {
                pre = pre->rightchild;
            }
            
            //if find right most node of left subtree
            if(pre->rightchild == NULL)
            {
                pre->rightchild = cur;
                cur = cur->leftchild;
            }
            else
            {
                //if find here, means travel to leftmost subtree, so print and turn right
                pre->rightchild = NULL;
                std::cout << cur->data << " ";
                cur = cur->rightchild;
            }
        }
    }
    std::cout << std::endl;
}

void morrispreorder(node* root)
{
    node* cur = root;
    
    while (cur)
    {
        //if left subtree does not exit
        if (cur->leftchild == NULL) {
            std::cout << cur->data << " ";
            cur = cur->rightchild;
        }
        //else find rightmost node of subtree, set its rightchild to cur
        else
        {
            node* pre = cur->leftchild;
            
            while (pre->rightchild!=NULL && pre->rightchild!=cur) {
                pre = pre->rightchild;
            }
            
            //if find right most node of left subtree
            if(pre->rightchild == NULL)
            {
                std::cout << cur->data << " ";
                pre->rightchild = cur;
                cur = cur->leftchild;
            }
            else
            {
                //if find here, means travel again, so does not print and turn right
                pre->rightchild = NULL;
                cur = cur->rightchild;
            }
        }
    }
    std::cout << std::endl;
}

//breath first travesal
//use queue
void breathfirst(node* root)
{
    if(root == NULL) return;
    
    std::queue<node *> nqueue;
    nqueue.push(root);
    
    while (!nqueue.empty()) {
        node* cur = nqueue.front();
        std::cout << cur->data << " ";
        nqueue.pop();
        if (cur->leftchild)
            nqueue.push(cur->leftchild);
        if(cur->rightchild)
            nqueue.push(cur->rightchild);
    }
    std::cout << std::endl;
}
