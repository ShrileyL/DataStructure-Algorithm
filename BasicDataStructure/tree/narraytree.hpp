//
//  tree.hpp
//  test
//
//  Created by Shulin on 2018/7/29.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#ifndef narraytree_hpp
#define narraytree_hpp

#include <iostream>
#include <vector>
struct NarrayNode
{
    int val;
    std::vector<NarrayNode*> children;
    NarrayNode(int _val, std::vector<NarrayNode*> _children) {
        val = _val;
        children = _children;
    }
};

std::vector<int> iterpostordertree(NarrayNode* root);

#endif /* narraytree_hpp */
