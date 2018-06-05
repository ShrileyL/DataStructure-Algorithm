//
//  btree.cpp
//  test
//
//  Created by Shulin on 2018/6/4.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include <stdio.h>
#include "tree.hpp"
#include <iostream>
#include <stack>
#include <queue>

int maxDepthRecursive(node* root)
{
    return root? std::max(maxDepthRecursive(root->leftchild),maxDepthRecursive(root->rightchild))+1:0;
}

// int maxDepthQue1(node* root)
// {
//     if(!root) return 0;
    
//     int res = 0;
//     std::queue<node *> q;
//     q.push(root);
    
//     while (!root) {
//         int size = q.size();
//         //pop out current layer nodes
//         for (int i=0; i<size; ++i) {
//             node* n = q.front();
//             q.pop();
//             if(n->leftchild) q.push(n->leftchild);
//             if(n->rightchild) q.push(n->rightchild);
//         }
//         ++res;
        
//     }
//     return res;
// }

// int maxDepthQue2(node* root)
// {
//     if(!root) return 0;
    
//     int res = 0;
//     std::queue<node *, int> q;
//     q.push(root,1);
    
//     while (!q.empty()) {
//         node* n = q.front().first;
//         int currentDepth = q.front().second;
//         //pop out current nodes
//         q.pop();
        
//         res = std::min(res,currentDepth);
//         if(n->leftchild) q.push(std::make_pair(n->leftchild,currentDepth+1) );
//         if(n->rightchild) q.push(std::make_pair(n->rightchild,currentDepth+1));
        
//     }
//     return res;
// }

// int maxDepthStack(node* root)
// {
//     if(!root) return 0;
    
//     int res = 0;
//     std::stack<node *, int> s;
//     s.push(root,1);
    
//     while (!s.empty()) {
//         node* n = s.top().first;
//         int currentDepth = qs.top().second;
//         //pop out current nodes
//         s.pop();
        
//         res = std::min(res,currentDepth);
//         if(n->leftchild) s.push(std::make_pair(n->leftchild,currentDepth+1) );
//         if(n->rightchild) s.push(std::make_pair(n->rightchild,currentDepth+1));
        
//     }
//     return res;
// }
