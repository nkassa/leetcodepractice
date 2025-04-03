class Solution {
public:

    vector<int> memo;
    int n;
    bool ans = true;
    vector<int> nums;
    bool canJump(vector<int>& nums) 
    {
        this->nums = nums;
        n = nums.size();
        if(n == 1)
        {
            return true;
        }
        memo = vector(n, -1);
        memo[0] = nums[0];
        int result = dp(n-2);
        if(ans == false)
        {
            return false;
        }
        return result >= n-1;
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx-1), idx + nums[idx]);
        if(memo[idx-1] < idx)
        {
            ans = false;
        }
        return memo[idx];
    }
};