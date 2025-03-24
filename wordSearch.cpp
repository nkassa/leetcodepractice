class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<char>> board;
    bool exist(vector<vector<char>>& board, string word) 
    {
        this->board = board;
        m = board.size();
        n = board[0].size();
        vector<vector<int>> starts;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(word[0] == board[i][j])
                {
                    starts.push_back({i,j});
                }
            }
        }
        vector<vector<bool>> seen;
        seen = vector(m, vector<bool> (n, false)); 
        string curr = "";
        curr += word[0];
        for(auto start: starts)
        {
            seen[start[0]][start[1]] = true;
            bool ans = backtrack(start, word, seen, curr, 0);
            if(ans == true)
            {
                return true;
            }
        }
        return false;
    }
    bool backtrack(vector<int> start, string& word, vector<vector<bool>> seen, string curr, int idx)
    {
        if(curr == word)
        {
            return true;
        }
        if(curr.back() != word[idx])
        {
            return false;
        }
        for(vector<int> direction: directions)
        {
            int nextRow = start[0] + direction[0];
            int nextCol = start[1] + direction[1];
            if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                curr += word[idx];
                backtrack({nextRow, nextCol}, word, seen, curr, idx += 1);
                curr.pop_back();
                seen[nextRow][nextCol] = false;
            }
        }
        return false;
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};