//
//  tree.hpp
//  test
//
//  Created by Shulin on 2018/5/31.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
struct node
{
    int data;
    node *leftchild;
    node *rightchild;
    node(int val)
    {
        data = val;
        leftchild = NULL;
        rightchild = NULL;
    }
};

void insert(node* root,int val);
//recursion
void preordertree(node* root);
void postordertree(node* root);
void inordertree(node* root);

//iterative
void iterpreordertree(node* root);
void iterpostordertree(node* root);
void iterinordertree(node* root);

//morris method
void morrispreorder(node* root);
void morrisinorder(node* root);

//breath first or level first travesal
void breathfirst(node* root);

#endif /* tree_hpp */
