class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    int numIslands(vector<vector<char>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        seen = vector(m, vector<bool>(n, false));
        queue<pair<int, int>> queue;
        int ans = 0;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(!seen[row][col] && grid[row][col] == '1')
                {
                    ans++;
                    queue.push({row,col});
                    seen[row][col] = true;
                    while(!queue.empty())
                    {
                        int Row = queue.front().first;
                        int Col = queue.front().second;
                        queue.pop();
                        for(vector<int> direction: directions)
                        {
                            int nextRow = direction[0] + Row;
                            int nextCol = direction[1] + Col;
                            if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
                            {
                                queue.push({nextRow, nextCol});
                                seen[nextRow][nextCol] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1';
    }
};
