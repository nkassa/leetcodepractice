class Solution {
public:
    vector<int> memo;
    int n;
    bool canJump(vector<int>& nums) 
    {
        n = nums.size();
        memo = vector(n+1, -1);
        memo[0] = 0;
        return dp(n);
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx-1), idx-1 + nums[idx-1]);
        return memo[idx];
    }
};