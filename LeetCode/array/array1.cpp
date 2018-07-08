//
//  array.hpp
//  test
//
//  Created by Shulin on 2018/7/8.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include "array.hpp"
#include <iostream>
#include <tr1/unordered_set>
#include <algorithm> 
using namespace std;

int findMin(vector<int>& nums)
{
        int size = nums.size();
        
        if(size == 0)
        {
            return 0;
        }
        else if(size == 1)
            return nums[0];
        else if(size == 2)
            return min(nums[0],nums[1]);
        
        int start = 0;
        int stop = size - 1;
        
        while(start < stop-1)
        {
            if(nums[start] < nums[stop])
                return nums[start];
            
            int mid  = (start +stop) /2;
            if(nums[start] < nums[mid])//left sub sorted
            {
                start = mid;
            }
            else if(nums[mid] < nums[start])
                stop = mid;
        }
        
        return min(nums[start],nums[stop]);
}

int singleNonDuplicate(vector<int>& nums) 
{
        if(nums.size()==1) return nums[0];
        
        int n = nums.size();
        int start = 0, stop = n-1;
        while(start < stop)
        {
            int mid = (start + stop)/2;
            if(nums[mid] == nums[mid-1]){
                if((n-1-mid)%2==0)//even
                    stop = mid;
                else
                    start = mid+1;
            }
            
            else
            {
                if(nums[mid] != nums[mid+1])
                    return nums[mid];
                if((n-1-mid)%2 == 1)
                    stop = mid;
                else
                    start = mid+1;
            }
                
        }
        return nums[start];
    }