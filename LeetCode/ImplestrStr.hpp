// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")//if neddle is empty
            return 0;
        
        int findIndex = 0;
        bool flag = false, find = false;
        
        for(int i = 0; i < haystack.size(); ++i)
        {
            if(haystack[i] == needle[0])//possible index
            {
                if(i+needle.size() <= haystack.size())
                {
                    for(int j = 0; j < needle.size(); ++j)
                    {
                        if(needle[j] != haystack[i + j])
                            flag = true;
                    }
                    if(!flag)
                    {
                        findIndex = i;
                        find = true;
                        break;
                    }
                        
                }
            }
            flag = false;//reset flag
        }
        if(find)
            return findIndex;
        else
            return -1;
    }
};