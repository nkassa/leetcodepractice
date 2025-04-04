class Solution {
public:
    vector<int> memo;
    int n;
    vector<int> nums;
    bool canJump(vector<int>& nums) 
    {
        this->nums = nums;
        n = nums.size();
        if(n == 1)
        {
            return true;
        }
        memo = vector(n+1, -1);
        memo[0] = 0;
        return dp(n-1) >= n-1;
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = max(dp(idx-1), idx-1 + nums[idx-1]);
        cout << memo[idx] << endl;
        return memo[idx];
    }
};