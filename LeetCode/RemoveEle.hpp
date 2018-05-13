// Given an array nums and a value val, remove all instances of that value in-place and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example 1:

// Given nums = [3,2,2,3], val = 3,

// Your function should return length = 2, with the first two elements of nums being 2.

// It doesn't matter what you leave beyond the returned length.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
        
//         if(nums.size() == 0)
//             return 0;
        
//         int start = 0, end = nums.size()-1;
//         while(start <= end)
//         {
//             if(nums[start] != val) {++start;continue;}
//             if(nums[end] == val){--end;continue;}
//             //swap
//             int temp = nums[start];
//             nums[start] = nums[end];
//             nums[end] = temp;
            
//             ++start;
//             --end;
//         }
//         return (start);
        
    }
};