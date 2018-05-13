// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        
        string result;
        char current;
        //find min length
        int min = strs[0].length();
        for (int i=1; i<strs.size(); i++)
            if (strs[i].length() < min)
                min = strs[i].length();
        
        for(int i = 0; i < min; ++i)
        {
            current = strs[0][i];
            
            for(int j = 0; j < strs.size(); ++j)
            {

                if(strs[j][i] != current)
                    return result;
            }
            result.push_back(current);
           
        }
        
        return result;
    }
};