class Solution {
public:
    vector<vector<int>> obstacleGrid;
    vector<vector<int>> memo;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        this->obstacleGrid = obstacleGrid;
        memo = vector(m, vector<int>(n, -1));
        memo[0][0] = 1;
        return dp(m-1, n-1);
    }
    int dp(int row, int col)
    {
        if(memo[row][col] != -1)
        {
            return memo[row][col];
        }
        int way = 0;
        if(row > 0)
        {
            way += dp(row-1, col);
        }
        if(col > 0)
        {
            way += dp(row, col-1);
        }
        if(obstacleGrid[row][col] == 1)
        {
            way = 0;
        }
        memo[row][col] = way;
        return memo[row][col];
    }
};