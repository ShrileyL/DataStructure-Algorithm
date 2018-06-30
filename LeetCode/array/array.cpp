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

void display(std::vector<int>& v)
{
    for(int i=0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void display(std::vector<int>& v, int size)
{
    for(int i = 0; i<size; i++)
        cout << v[i] << " ";
    cout << endl;
}

int removeDuplicates(std::vector<int>& nums)
{
    if(nums.size()==0) return 0 ;
    int index = 1;
    for (int i = 0; i < nums.size()-1; ++i)
    {
        if(nums[i]!=nums[i+1])
            nums[index++] = nums[i+1];
    }
    return index;
}

int removeDuplicatesII(std::vector<int>& nums)
{
    if(nums.size()==0) return 0 ;
    int index = 0;
    int count = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        if(nums[index]==nums[i])
        {
            count++;
            if(count < 2)
                nums[++index] = nums[i];
        }
        else
        {
            nums[++index] = nums[i];
            count = 0;
        }
    }
    return index+1;
}

std::vector<int> plusOne(std::vector<int>& digits)
{
    int sum = 0;
    int one = 1;
    std::vector<int> res(digits.size(),0);
    for (int i = digits.size()-1; i >= 0; --i)
    {
        sum = one + digits[i];
        one = sum / 10;
        res[i] = sum % 10;
    }

    if(one > 0)
        res.insert(res.begin(),one);

    return res;
}

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