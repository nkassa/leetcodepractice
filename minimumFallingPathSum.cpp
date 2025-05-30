class Solution {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int m;
    int n;
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        this->matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
        memo = vector(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            memo[0][i] = matrix[0][i];
        }
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, dp(m-1, i));
        }
        return ans;
    }
    int dp(int row, int col)
    {
        if(memo[row][col] != INT_MAX)
        {
            return memo[row][col];
        }
        int sum = INT_MAX;
        if(row > 0)
        {
            sum = min(sum, dp(row-1, col));
        }
        if(row > 0 && col > 0)
        {
            sum = min(sum, dp(row-1, col-1));
        }
        if(row > 0 && col < n-1)
        {
            sum = min(sum, dp(row-1, col+1));
        }
        sum += matrix[row][col];
        memo[row][col] = sum;
        return memo[row][col];
    }
};