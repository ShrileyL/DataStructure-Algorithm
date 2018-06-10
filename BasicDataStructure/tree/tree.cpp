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

node* mergeTrees(node* t1, node* t2)
{
    if(t1 == NULL)
        return t1;
    if(t2 == NULL)
        return t2;

    t1->data += t2->data;
    t1->leftchild = mergeTrees(t1->leftchild,t2->leftchild);
    t1->rightchild = mergeTrees(t1->rightchild,t2->rightchild);

    return t1;
}

node* itermergeTrees(node* t1, node* t2)
{
    if(t1 == NULL)
        return t1;
    if(t2 == NULL)
        return t2;

    std::stack<node*> nstack ;
    node* tmp = new node(0);
    tmp->leftchild = t1;
    tmp->rightchild = t2;
    nstack.push(tmp);

    node* n = new node(0);
    while(!nstack.empty())
    {
        n = nstack.top();
        nstack.pop();
        if(n->leftchild == NULL || n->rightchild == NULL)
        {
            continue;
        }
        n->leftchild->data += n->rightchild->data;

        if(n->leftchild->leftchild == NULL)
            n->leftchild->leftchild = n->rightchild->leftchild;
        else
        {
            node* t = new node(0);
            t->leftchild = n->leftchild->leftchild;
            t->rightchild = n->rightchild->leftchild;
            nstack.push(t);
        }

        if(n->leftchild->rightchild == NULL)
            n->leftchild->rightchild = n->rightchild->rightchild;
        else
        {
            node* t = new node(0);
            t->leftchild = n->leftchild->rightchild;
            t->rightchild = n->rightchild->rightchild;
            nstack.push(t);
        }
    }

    return t1;
}

bool isSameTree(node* p, node* q)
{

    if(p==NULL && q==NULL)
        return true;
    if((p==NULL&&q!=NULL) || (NULL!=p)&&(NULL==q))
        return false;
    if(p->data != q->data)
        return false;
        
    return isSameTree(p->leftchild,q->rightchild) && isSameTree(p->leftchild,q->rightchild);
}

int findTilt(node* root) 
{
    if(root == NULL) return 0;
    int res = 0;
    postordertilt(root,res);
    return res;
}
    
    //res: tilt result
int postordertilt(node* root, int &res)
{
    if(root == NULL) return 0;
    int leftsum = postordertilt(root->leftchild,res);
    int rightsum = postordertilt(root->rightchild,res);
    res += abs(leftsum - rightsum);
    return leftsum + rightsum + root->data;
}

int abs(int a)
{
    if(a < 0)
        return -a;
    else
        return a;
}