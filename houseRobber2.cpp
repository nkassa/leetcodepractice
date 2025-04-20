class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> memo;
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return 0;
        }
        memo[0] = nums[0];
        memo[1] = nums[1];
        int ans = 0;
        int curr = 0;
        for(int i = 2; i < n-1; i++)
        {
            curr += memo[i-2] + nums[i];
        }
        ans = max(curr, ans);
        for(int i = 3; i < n-1; i++)
        {
            curr += memo[i-2] + nums[i];
        }
        ans = max(curr, ans);
        return ans;
    }
};