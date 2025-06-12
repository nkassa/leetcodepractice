class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) 
    {
        memo = vector<int>(n+1, -1);
        memo[0] = 1;
        memo[1] = 1;
        return dp(n);
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = dp(idx-1) + dp(idx-2);
        return memo[idx];
    }
};