// Examples:
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int coef = 1;
        for(int i = 0; i < numRows; ++i)
        {
            vector<int> added;
            for(int j = 0; j <= i; ++j)
            {
                if(j == 0 || i == 1)
                    coef = 1;
                else
                    coef = coef*(i-j+1)/j;
                
                added.push_back(coef);
            }
            result.push_back(added);
        }
        return result;
    }
};