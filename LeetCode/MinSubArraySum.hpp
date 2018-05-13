// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// Example: 

// Input: [2,3,1,2,4,3], s = 7
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
// Follow up:
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

class Solution {
public:
 
    int minSubArrayLen(int s, vector<int>& nums) {
        
    // Initialize current sum and minimum length
    int n = nums.size();
    int curr_sum = 0, min_len = n+1;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n)
    {
        // Keep adding array elements while current sum
        // is smaller than s
        while (curr_sum < s && end < n)
            curr_sum += nums[end++];
 
        // If current sum becomes greater than s.
        while (curr_sum >= s && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;
 
            // remove starting elements
            curr_sum -= nums[start++];
        }
    }
        if(min_len == n+1)
            return 0;
  
        return min_len;
    }
};