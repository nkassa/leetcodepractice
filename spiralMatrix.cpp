class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int row = 0;
        int col = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans = {};
        while(row < m && col < n)
        {
            for(int i = col; i < n; i++)
            {
                ans.push_back(matrix[row][i]);
            }
            row++;
            for(int i = row; i < m; i++)
            {
                ans.push_back(matrix[i][n-1]);
            }
            n--;
            for(int i = n-1; i >= col; i--)
            {
                ans.push_back(matrix[m-1][i]);
            }
            m--;
            for(int i = m-1; i >= row; i--)
            {
                ans.push_back(matrix[i][col]);
            }
            col++;
        }
        return ans;
    }
};