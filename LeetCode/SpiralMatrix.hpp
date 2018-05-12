// // Given a matrix of m x n elements (m rows, n columns), 
// // return all elements of the matrix in spiral order.

// Example:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
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
        vector<int> result;
        
        int x= 0, y = 0, i = 0;
        int dx = 0, dy = 1;
        bool **flag = new bool*[m];//create flag matrix
        for(i =0; i < m; ++i)
            flag[i] = new bool[n];
        for(i= 0;i<m; ++i)
            for(int j = 0; j < n;++j)
                flag[i][j] = false;
        
        for(i = 0; i < m*n; ++i)
        {
            result.push_back(matrix[x][y]);
            flag[x][y] = true;
            int nx = x + dx;
            int ny = y + dy;
            if(nx < m && nx >= 0 && ny >= 0 && ny < n)
            {
                if(!flag[nx][ny])//go with the same direction
                {
                    x = nx;
                    y = ny;
                    continue;
                }
            }
            if(y < n-1 && (!flag[x][y + 1]))//try right
            {
                ++y;
                dx = 0;
                dy = 1;
                continue;
            }
            if(x < m-1 && (!flag[x + 1][y]))//try down
            {
                ++x;
                dx = 1;
                dy = 0;
                continue;
            }
            if(y > 0 && (!flag[x][y - 1]))//try left
            {
                --y;
                dx = 0;
                dy = -1;
                continue;
            }
            if(x > 0 && (!flag[x-1][y]))//try right
            {
                --x;
                dx = -1;
                dy = 0;
                continue;
            }
            break;
        }

        return result;
    }
};