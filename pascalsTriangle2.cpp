class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>> memo;
        for(int i = 0; i <= rowIndex; i++)
        {
            vector<int> curr (i+1, 1);
            for(int j = 1; j < i; j++)
            {
                curr[j] = memo[i-1][j-1] + memo[i-1][j];
            }
            memo.push_back(curr);
        }
        return memo[rowIndex];
    }
};