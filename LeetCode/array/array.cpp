//
//  array.hpp
//  test
//
//  Created by Shulin on 2018/6/15.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include "array.hpp"
#include <iostream>
#include <tr1/unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	std::tr1::unordered_set<int> seen;
    std::tr1::unordered_set<int> inter;
        
    //push all element in numsi to set:seen
    for(int i = 0; i < nums1.size() ;++i)
        seen.insert(nums1[i]);
        
    for(int i = 0; i < nums2.size() ;++i)
    {
        if(seen.find(nums2[i]) != seen.end())
            inter.insert(nums2[i]);
    }
        
    vector<int> res(inter.begin(),inter.end());
        
    return res;
}