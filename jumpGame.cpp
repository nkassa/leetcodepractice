class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        memo[0] = nums[0];

        if(n == 1)
        {
            return true;
        }
        for(int i = 1; i < nums.size()-1; i++)
        {
            if(memo[i-1] < i)
            {
                return false;
            }
            memo[i] = max(memo[i-1], i + nums[i]);
        }
        return memo[n-2] == n-1;
    }
};