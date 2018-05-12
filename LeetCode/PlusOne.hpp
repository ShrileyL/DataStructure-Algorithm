// Given a non-empty array of digits representing 
// a non-negative integer, plus one to the integer.

// The digits are stored such that the most significant 
// digit is at the head of the list, and each element in the array contain a single digit.

// You may assume the integer does not contain any leading zero, 
// except the number 0 itself.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        bool needadd = false;
        digits[digits.size()-1] += 1;
        for(int i = digits.size()-1; i > -1; --i)
        {
            if(needadd)
                digits[i] += 1;
            
            //reset to false
            needadd = false;
            
            if(digits[i] == 10)
            {
                digits[i] = 0;
                needadd = true;
            }
        }
        vector<int> result(digits.begin(),digits.end());
        if(needadd)
        {
            auto it = result.begin();
            result.insert(it,1);
        }
        
        return result;
    }
};