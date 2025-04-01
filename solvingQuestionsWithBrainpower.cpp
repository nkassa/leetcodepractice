class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        long n = questions.size();
        vector<long> dp(n+1, -1);
        dp[n-1] = questions[n-1][0];
        dp[n] = 0;

        for(int i = n-1; i >= 0; i--)
        {
            long j = i + questions[i][1] + 1;
            dp[i] = max(dp[i+1] , questions[i][0] + dp[min(j, n)]);
        }
        return dp[0];
    }
};