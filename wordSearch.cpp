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
                    seen[i][j] = true;
                    backtrack(0, word, seen, board, i, j);
                    if(ans == true)
                    {
                        return true;
                    }
                    seen[i][j] = false;
                }
            }
        }
        return false;
    }
    void backtrack( int idx, string& word, vector<vector<bool>>& seen,  vector<vector<char>>& board, int i, int j)
    {
        if(idx == word.size()-1)
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
            if(board[i][j] == word[idx])
            {
                int nextRow = i + direction[0];
                int nextCol = j + direction[1];
                if(valid(nextRow, nextCol, word, idx + 1) && !seen[nextRow][nextCol])
                {
                    seen[nextRow][nextCol] = true;
                    backtrack(idx + 1, word, seen, board, nextRow, nextCol);
                    seen[nextRow][nextCol] = false;
                }
            }
        }
    }
    bool valid(int row, int col, string& word, int idx)
    {
        return 0 <= row && row < m && 0 <= col && col < n && board[row][col] == word[idx];
    }
};