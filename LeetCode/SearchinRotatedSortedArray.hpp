// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchRotated(nums, 0, nums.size()-1, target);
    }
    
    int searchRotated(vector<int>& nums, int start, int end, int target)
    {
        if(start > end) return -1;
        int mid = (start + end) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < nums[end])//right part sorted
        {
            if(nums[end] >= target && target > nums[mid])
                return searchRotated(nums, mid+1, end, target);
            else
                return searchRotated(nums, start, mid-1, target);
        }
        else//left part sorted
        {
            if(nums[start] <= target && target < nums[mid])
                return searchRotated(nums, start, mid-1, target);
            else
                return searchRotated(nums, mid+1, end, target);
        }
    }
};