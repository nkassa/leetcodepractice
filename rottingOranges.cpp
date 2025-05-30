class Solution {
public:
    int ans = 0;
    int m;
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    vector<vector<int>> grid;
    int one = 0;
    int orangesRotting(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        queue<vector<int>> queue;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 2)
                {
                    queue.push({row,col,0});
                    seen[row][col] = true;
                }
                else if(grid[row][col]== 1)
                {
                    one += 1;
                }
            }
        }
        while(!queue.empty())
        {
            int row = queue.front()[0];
            int col = queue.front()[1];
            int cnt = queue.front()[2];
            queue.pop();
            ans = max(ans,cnt);
            cnt++;
            for(vector<int> direction: directions)
            {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
                {
                    seen[nextRow][nextCol] = true;
                    one--;
                    queue.push({nextRow, nextCol, cnt});
                }
            }
        }
        if(one == 0)
        {
            return ans;
        }
        return -1;
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == 1;
    }
};