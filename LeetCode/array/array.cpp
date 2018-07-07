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
#include <algorithm> 
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

std::vector<std::vector<int> > generate(int numRows)
{
    std::vector<std::vector<int> > vals;
    vals.resize(numRows);

    // 1. layer k contains k element
    // 2. the first and last element in kth layer are 1
    // 3. for kth(k>2) layer,for element n(n > 1 && n < k):
    //    A[k][n] = A[k-1][n-1] + A[k-1][n]
    for (int i = 0; i < numRows; ++i)
    {
        // 1
        vals[i].resize(i+1);
        // 2
        vals[i][0] = 1;
        vals[i][vals[i].size()-1] = 1;
        // 3
        for (int j = 1; j < vals[i].size()-1; ++j)
        {
            vals[i][j] = vals[i-1][j-1]+vals[i-1][j];
        }
    }
    return vals;
}

std::vector<int> getRow(int rowIndex)
{
    std::vector<int > vals;

    vals.resize(rowIndex+1,1);

    for (int i = 0; i < rowIndex+1; ++i)
    {
        for (int j = i-1; j >= 1 ; --j)
        {//find element j, j > 0&& j < i
            vals[j] = vals[j]+vals[j-1];
        }
    }
    return vals;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    if(n == 0 && m==0) return;
    else if(m == 0)
    {
        for(int i = 0; i < n; i++)
            nums1[i] = nums2[i];
    }
    else if(n == 0)
        return;
    int ix1 = m-1, ix2 = n-1;
    for (int i = m+n-1; i >= 0; --i)
    {
        if(ix1>=0 && ix2>=0)
        {
        if(nums1[ix1]>nums2[ix2])
            nums1[i] = nums1[ix1--];
        else
            nums1[i] = nums2[ix2--];
        }
        else if(ix1 >= 0)
            nums1[i] = nums1[ix1--];
        else
            nums1[i] = nums2[ix2--];
    }

}

// vector<int> twoSum(vector<int>& nums, int target)
// {
//     std::vector<int> res;
//     if(nums.size() <= 1)
//         return res;

//     std::tr1::unordered_set<int,int> map;
//     for (int i = 0; i < nums.size(); ++i)
//         map[nums[i]] = i;

//     for (int i = 0; i < nums.size(); ++i)
//     {
//         int rest_val = target - nums[i];
//         if(map.find(rest_val) != map.end())
//         {
//             int index = map[rest_val];
//             if (index==i)
//                 continue;
//             if(index < i)
//             {
//                 res.push_back(index);
//                 res.push_back(i);
//                 return res;
//             }
//             else
//             {
//                 res.push_back(i);
//                 res.push_back(index);
//                 return res;
//             }
//         }
//     }
// }

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> res;
    if(nums.size() < 2)
        return res;
    std::sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size()-1;i++)
    {
        if(i > 0 && nums[i-1] == nums[i]) continue;
        int j = i+1;
        while( j < nums.size())
        {
            if(nums[i] + nums[j] == target)
            {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                j++;
                while(nums[j] == nums[j-1]) j++;
            }
        }
    }
    return res;
}

vector<vector<int> > threeSum(vector<int>& nums) 
{
    return threeSumUlti(nums,0);
}
vector<vector<int> > threeSumUlti(vector<int>& num, int target)
    {
        vector<vector<int> > res;
        if(num.size()<3) return res;
        
        std::sort(num.begin(),num.end());
        for(int i = 0; i < num.size() - 1; i++)
        {
            if(i>0&&num[i]==num[i-1]) continue;
            int left = i+1;
            int right = num.size()-1;
            while(left < right)
            {
                int curSum = num[left] + num[right];
                int curTarget = target - num[i];
                if(curSum == curTarget)
                {
                    vector<int> sul;
                    sul.push_back(num[i]);
                    sul.push_back(num[left]);
                    sul.push_back(num[right]);
                    res.push_back(sul);
                    left++;
                    right--;
                    while(num[left]==num[left-1]) left++;
                    while(num[right]==num[right+1]) right--;
                }
                else if(curSum < curTarget)
                    left++;
                else
                    right--;
            }
        }
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