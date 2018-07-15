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

 double findMedianSortedArrays(const std::vector<int>& nums1,const std::vector<int>& nums2)
 {
 	int m=nums1.size(), n=nums2.size();
        int total = m+n;
        if((m+n)%2==0)//need to find (m+n)/2 and(m+n)/2 +1 elements
            return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2) + find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
        else
            return find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1);
 }

int find_kth(std::vector<int>::const_iterator A,int m,std::vector<int>::const_iterator B,int n,int k)
{
	//ensure m < n
        if(m > n)
            return find_kth(B,n,A,m,k);
        if(m == 0)
            return *(B+k-1);
        if(k == 1)
            return min(*A,*B);
        
        //divide k into  two parts
        int ia = min(k/2,m),ib = k - ia;
        if(*(A+ia-1)<*(B+ib-1))//delete ia elemnts
            return find_kth(A+ia,m-ia,B,n,k-ia);
        else if(*(A+ia-1)>*(B+ib-1))
            return find_kth(A,m,B+ib,n-ib,k-ib);
        else
            return *(A+ia-1);
}