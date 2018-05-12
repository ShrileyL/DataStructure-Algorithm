// Largest Number At Least Twice of Others

// In a given integer array nums, there is always exactly one largest element.

// Find whether the largest element in the array is at least twice as much as every other number in the array.

// If it is, return the index of the largest element, otherwise return -1.

class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        int maxIndex = 0;
        int max = nums[maxIndex];
        bool flag = false;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= max)
            {
                maxIndex = i;
                max = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if(i != maxIndex)
                if(nums[i]*2 > max)
                    flag = true;
        }
        if(flag)
            return -1;
        else
            return maxIndex;
        
    }
};