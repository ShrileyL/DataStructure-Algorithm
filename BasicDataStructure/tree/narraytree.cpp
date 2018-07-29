//
//  tree.cpp
//  test
//
//  Created by Shulin on 2018/7/29.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include "narraytree.hpp"
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

// //recursion
// void preordertree(NarrayNode* root)
// {
//     if(root == NULL) return;
//     if(root!=NULL)
//     {
//     std::cout << root->data << " ";
//     preordertree(root->leftchild);
//     preordertree(root->rightchild);
//     }
// };
// void postordertree(NarrayNode* root)
// {
//     if(root == NULL) return;
//     if(root)
//     {
//         postordertree(root->leftchild);
//         postordertree(root->rightchild);
//         std::cout << root->data << " ";
//     }
// }
// void inordertree(NarrayNode* root)
// {
//     if(root)
//     {
//         inordertree(root->leftchild);
//         std::cout << root->data << " ";
//         inordertree(root->rightchild);
//     }
// }

//iterative
// void iterpreordertree(node* root)
// {
//     if(root == NULL) return;
    
//     std::stack<node *> nstack;
//     nstack.push(root);
    
//     while(!nstack.empty())
//     {
//         node* tmp = nstack.top();
//         std::cout << tmp->data << " ";
//         nstack.pop();
        
//         if(tmp->rightchild)
//             nstack.push(tmp->rightchild);
//         if (tmp->leftchild)
//             nstack.push(tmp->leftchild);
//     }
//     std::cout << std::endl;
// }
std::vector<int> iterpostordertree(NarrayNode* root)
{
    std::vector<int> res;
    std::stack<NarrayNode*> stk;
        if(root==NULL)
            return res;
        else
            stk.push(root);
        while(!stk.empty())
        {
            NarrayNode* cur = stk.top();
            stk.pop();
            for(int i=0;i < cur->children.size();i++)
            {
                stk.push(cur->children[i]);
            }
            
            res.push_back(cur->val);
        }
        std::reverse(res.begin(),res.end());
        return res;
}
// void iterinordertree(node* root)
// {
//     if(root == NULL) return;
    
//     std::stack<node *> nstack;
//     node* cur = root;
    
//     while(cur || !nstack.empty())
//     {
//         //ifcur is not NULL
//         if(cur)
//         {
//             nstack.push(cur);
//             cur = cur->leftchild;
//         }
//         else{
//             cur = nstack.top();
//             std::cout << cur->data << " ";
//             nstack.pop();
            
//             cur = cur->rightchild;
//         }
//     }
    
//     std::cout << std::endl;
// }
