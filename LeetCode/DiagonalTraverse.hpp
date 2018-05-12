// Given a matrix of M x N elements (M rows, N columns), return all 
// elements of the matrix in diagonal order as shown in the below image.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
 
        int m = matrix.size();
        if (m == 0)
            return vector<int>();
        if (m == 1)
            return matrix[0];
        int n = matrix[0].size();
        if (n == 0)
            return vector<int>();
        if (n == 1) 
        {
            vector<int> results(m);
            for (int i = 0;i < m;++i)
                results[i] = matrix[i][0];
            return results;
        }
        
    int i = 0, j = 0, pos = 0;
    bool upright = true;
    vector<int> results(m*n);
    while (!(i == m-1 && j == n-1)) {
        results[pos++] = matrix[i][j];
        if (upright) {
            if (j == n-1) {
                ++i;
                upright = !upright;
            }
            else if (i == 0) {
                ++j;
                upright = !upright;
            }
            else {
                --i;
                ++j;
            }
        }
        else {
            if (i == m-1) {
                ++j;
                upright = !upright;
            }
            else if (j == 0) {
                ++i;
                upright = !upright;
            }
            else {
                ++i;
                --j;
            }
        }
    }
    results[pos] = matrix[m-1][n-1];
    return results;
    }
};