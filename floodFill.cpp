class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    int m;
    int n;
    int val;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        m = image.size();
        n = image[0].size();
        seen = vector(m, vector<bool>(n, false));
        val = image[sr][sc];
        image[sr][sc] = color;
        seen[sr][sc] = true;
        dfs(sr, sc, color, image);
        return image;
    }
    void dfs(int row, int col, int color, vector<vector<int>>& image)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(valid(nextRow, nextCol, image) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                image[nextRow][nextCol] = color;
                dfs(nextRow, nextCol, color, image);
            }
        }
    }
    bool valid(int row, int col, vector<vector<int>>& image)
    {
        return 0 <= row && row < m && 0 <= col && col < n && image[row][col] == val;
    }
};
