class Solution {
public:

    vector<long> memo;
    vector<vector<int>> questions;
    long n;

    long long mostPoints(vector<vector<int>>& questions) 
    {
        this->questions = questions;
        n = questions.size();

        memo = vector<long>(n+1, -1);
        memo[n-1] = questions[n-1][0];
        memo[n] = 0;

        return dp(0);
    }

    long dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }

        long j = idx + questions[idx][1] + 1;
        memo[idx] = max( dp(idx+1) , questions[idx][0] + dp(min(n, j)) );
        return memo[idx];
    }
};