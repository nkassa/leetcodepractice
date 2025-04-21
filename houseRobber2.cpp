class Solution {
public:
    int n;
    int rob(vector<int>& nums) 
    {
        int ans = 0;
        n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
        ans = dp(0, n-1, nums);
        ans = max(ans, dp(1, n, nums));
        return ans;
    }
    int dp(int start, int end, vector<int>& nums)
    {
        vector<int> memo(end, 0);
        memo[start] = nums[start];
        memo[start+1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i < end; i++)
        {
            memo[i] = max(memo[i-1], memo[i-2] + nums[i]);
        }
        return memo[end-1];
    }
};