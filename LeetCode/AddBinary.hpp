// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"


class Solution {
public:
    string addBinary(string a, string b) {
        //initial result
        string result = "";
        int s = 0;
        
        //travel from end of each string
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || s == 1)
        {
            // Comput sum of last digits and carry
            s += ((i >= 0)? a[i] - '0': 0);
            s += ((j >= 0)? b[j] - '0': 0);
 
            // If current digit sum is 1 or 3, add 1 to result
            result = char(s % 2 + '0') + result;
 
            // Compute carry
            s /= 2;
 
            // Move to next digits
            i--; j--;
        }
        return result;
    }
};