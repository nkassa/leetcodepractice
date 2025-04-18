class Solution {
public:
    int climbStairs(int n) 
    {
        if(n < 2)
        {
            return 1;
        }
        vector<int> memo(n, -1);
        memo[0] = 1;
        memo[1] = 2;
        for(int i = 2; i < n; i++)
        {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n-1];
    }
};