//
//  FenwickTree.hpp
//  leetcode_structure
//
//  Created by Shulin on 2019/4/28.
//  Copyright © 2019 Shulin. All rights reserved.
//

#ifndef FenwickTree_h
#define FenwickTree_h

#include<vector>
class FenwickTree {
public:
    FenwickTree(int n):_sum(n+1,0)
    {}
    
    void update(int i,int delta)
    {
        while (i < _sum.size()) {
            _sum[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const
    {
        int sum = 0;
        while (i > 0) {
            sum += _sum[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    //Fenwick tree index start from 1
    std::vector<int> _sum;
    static inline int lowbit(int x)
    {
        return x & (-x);
    }
};

#endif /* FenwickTree_h */
