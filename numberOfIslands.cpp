class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans= 0;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == '1' && seen[row][col] == false)
                {
                    ans++;
                    seen[row][col] = true;
                    dfs(row, col, grid);
                }
            }
        }
        return ans;
    }
    void dfs(int row, int col, vector<vector<char>>& grid)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(valid(nextRow, nextCol, grid) && seen[row][col] == false)
            {
                seen[row][col] = true;
                dfs(nextRow,nextCol, grid);
            }
        }
    }

    void valid(int row, int col, vector<vector<char>>& grid)
    {
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == 1;
    }

};