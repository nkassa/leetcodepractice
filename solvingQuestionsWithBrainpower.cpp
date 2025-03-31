class Solution {
public:
    vector<int> memo;
    vector<vector<int>> questions;
    int n;
    long long mostPoints(vector<vector<int>>& questions) 
    {
        this->questions = questions;
        n = questions.size();
        memo = vector(n, -1);
        memo[n-1] = questions[n-1][0];
        return dp(0);
    }

    long long dp(int idx)
    {
        if(idx > n-1)
        {
            return 0;
        }
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx+1), questions[idx][0] + dp(idx + questions[idx][1] + 1));
        return memo[idx];
    }
};