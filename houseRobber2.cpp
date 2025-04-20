class Solution {
public:
    vector<int> memo;
    vector<int> nums;
    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
        if(n == 3)
        {
            int x = max(nums[0], nums[1]);
            return max(x, nums[2]);
        }
        memo = vector(nums.size(), -1);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        int ans = 0;
        ans = max(ans, dp(n-2));
        ans = max(ans, dp(n-1));
        return ans;
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx-2) + nums[idx], dp(idx-1));
        return memo[idx];
    }
};