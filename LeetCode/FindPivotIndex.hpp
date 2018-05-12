// Find Pivot Index

// Given an array of integers nums, 
// write a method that returns the "pivot" index of this array.

// We define the pivot index as the index where the sum of the numbers 
// to the left of the index is equal to the sum of the numbers to the right of the index.

// If no such index exists, we should return -1.
// If there are multiple pivot indexes, you should return the left-most pivot index.

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int leftsum = 0,rightsum = 0,sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        for (int i = 0; i < nums.size(); ++i)
        {
            //rightsum = 0;
            if (i==0)
                leftsum = 0;
            else
                leftsum += nums[i-1];
            
            rightsum = sum - leftsum - nums[i];
            if(leftsum == rightsum)
                return i;
        }
        return -1;
        
    }
};