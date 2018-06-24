// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

// You are given a target value to search. If found in the array return true, otherwise return false.

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
// Follow up:

// This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// Would this affect the run-time complexity? How and why?

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size()-1, target);
    }
    
    bool binarysearch(vector<int>& nums, int start, int end, int target)
    {
        if(start > end) return false;
        int mid = (start + end) / 2;
        if(nums[mid]==target) return true;
        
        if(nums[mid] < nums[end])//right part sorted
        {
            if(target > nums[mid] && target <= nums[end])
                return binarysearch(nums,mid+1,end,target);
            else
                return binarysearch(nums,start,mid-1,target);
        }
        else if(nums[mid] > nums[end])
        {
            if(target >= nums[start] && target < nums[mid])
                return binarysearch(nums,start,mid-1,target);
            else
                return binarysearch(nums,mid+1,end,target);
        }
        else
            return binarysearch(nums,start, end-1,target);
    }
};