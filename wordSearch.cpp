class Solution {
public:

    int m;
    int n;

    bool ans = false;

    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<char>> board;

    bool exist(vector<vector<char>>& board, string word) 
    {
        this->board = board;
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> seen;
        seen = vector(m, vector<bool> (n, false)); 

        string curr = "";

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(word[0] == board[i][j])
                {
                    curr += board[i][j];
                    seen[i][j] = true;
                    backtrack(i, j, word, seen, curr, 0, board);
                    if(ans == true)
                    {
                        return true;
                    }
                }
            }
        }
        return ans;
    }
    void backtrack(int i, int j, string& word, vector<vector<bool>>& seen, string& curr, int idx, vector<vector<char>>& board)
    {
        if(curr.size() == word.size())
        {
            ans = true; 
            return;
        }
        for(vector<int> direction: directions)
        {
            if(ans == true)
            {
                break;
            }
            int nextRow = i + direction[0];
            int nextCol = j + direction[1];
            if(valid(nextRow, nextCol, word, idx+1) && !seen[nextRow][nextCol])
            {
                curr += board[i][j];
                seen[i][j] = true;
                backtrack(nextRow, nextCol, word, seen, curr, idx + 1, board);
                curr.pop_back();
                seen[i][j] = false;
            }
        }
        return;
    }
    bool valid(int row, int col, string& word, int idx)
    {
        return 0 <= row && row < m && 0 <= col && col < n && word[idx] == board[row][col];
    }
};