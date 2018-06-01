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
