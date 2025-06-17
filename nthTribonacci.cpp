class Solution {
public:
    vector<int> memo;
    int tribonacci(int n) 
    {
        if(n <= 1)
        {
            return n;
        }
        memo = vector(n+1, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return dp(n);
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = dp(idx-3) + dp(idx-2) + dp(idx-1);
        return memo[idx];
    }
};