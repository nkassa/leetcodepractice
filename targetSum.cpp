class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int curr = 0;
        int sol = 0;
        dp(curr, sol, nums, target, 0);
        return sol;
    }
    void dp(int curr, int& sol, vector<int>& nums, int& target, int idx)
    {
        if(idx == nums.size())
        {
            if(curr == target)
            {
                sol++;
            }
            return;
        }
        dp(curr - nums[idx], sol, nums, target, idx + 1);
        dp(curr + nums[idx], sol, nums, target, idx + 1);
    }
};