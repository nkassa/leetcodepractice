class Solution {
public:
    vector<int> memo;
    vector<int> nums;
    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        if(nums.size() == 1)
        {
            return nums[0];
        }
        memo = vector<int>(nums.size(), -1);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        return dp(nums.size()-1);
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx-1), dp(idx-2) + nums[idx]);
        return memo[idx];
    }
};