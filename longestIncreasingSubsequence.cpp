class Solution {
public:
    vector<int> memo;
    vector<int> nums;
    int lengthOfLIS(vector<int>& nums) 
    {
        this->nums = nums;
        memo = vector(nums.size(), -1);
        int ans = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, dp(i));
        }
        return ans;
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        int ans = 1; // base case 
        for(int i = 0; i < idx; i++)
        {
            if(nums[idx] > nums[i])
            {
                ans = max(ans, dp(i) + 1);
            }
        }
        memo[idx] = ans;
        return memo[idx];
    }
};