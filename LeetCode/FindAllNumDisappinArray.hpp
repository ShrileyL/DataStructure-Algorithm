// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
//some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? 
//You may assume the returned list does not count as extra space.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]


/*Solution 1:mark as negative*************************************/
class Solution {
public:
    
    // Because the original numbers are all positive, 
    //we can mark them as negative to indicate that a specific number appeared. 
    //Then we scan a 2nd time to see which indice are still positive, 
    //and that are the numbers missed.
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0)
                nums[idx] *= -1;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        
        return res;
    }
};

/*Solution 2:swap to proper position*************************************/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i+1){
                if (nums[nums[i]-1] == nums[i]) {
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != i+1) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};