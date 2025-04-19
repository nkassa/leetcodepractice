class Solution {
public:
    vector<int> nums;
    vector<int> memo;
    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        memo = vector(n, -1);
        if(nums[0] > nums[n-1])
        {
            nums[n-1] = 0;
        }
        else
        {
            nums[0] = 0
        }
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        return dp(n-1);
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx-2)+ nums[idx], dp(idx-1));
        return memo[idx];
    }
};