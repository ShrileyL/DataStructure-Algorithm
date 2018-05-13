// Write a function that takes a string as input and returns the string reversed.

// Example:
// Given s = "hello", return "olleh".

class Solution {
public:
    string reverseString(string s) {
        if(s.length() == 0)
            return "";
        
//         string result;
         int n = s.length();
//         // char* start = s[0];
//         // char* end = s[n-1];
//         for(int i = n-1;i >= 0; --i)
//             result.push_back(s[i]);
        
//         return result;

        int i,j;
        for(i = 0,j = n-1; i < j; ++i,--j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};