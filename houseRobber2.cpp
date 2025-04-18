class Solution {
public:
    vector<int> nums;
    vector<int> memo;
    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        nums.push_back(0);
        int n = nums.size();
        memo = vector(n, -1);
        memo[n-1] = nums[n-1];
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