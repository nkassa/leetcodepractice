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

        unordered_map<char, int> count;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                count[board[i][j]] += 1;
            }
        }

        unordered_map<char, int> count_word;
        for(int i = 0; i < word.size(); i++)
        {
            count_word[word[i]]++;
        }

        for(auto [key,val]: count_word)
        {
            if(count[key] < val)
            {
                return false;
            }
        }

        vector<vector<bool>> seen(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(word[0] == board[i][j])
                {
                    seen[i][j] = true;
                    backtrack(1, word, seen, i, j);
                    if(ans)
                    {
                        return true;
                    }
                    seen[i][j] = false;
                }
            }
        }
        return false;
    }
    void backtrack( int idx, string& word, vector<vector<bool>>& seen, int i, int j)
    {
        if(idx == word.size())
        {
            ans = true; 
            return;
        }
        for(vector<int> direction: directions)
        {
            if(ans)
            {
                break;
            }
            int nextRow = i + direction[0];
            int nextCol = j + direction[1];
            if(valid(nextRow, nextCol, word, idx) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                backtrack(idx + 1, word, seen, nextRow, nextCol);
                seen[nextRow][nextCol] = false;
            }
        }
    }
    bool valid(int row, int col, string& word, int idx)
    {
        return 0 <= row && row < m && 0 <= col && col < n && board[row][col] == word[idx];
    }
};