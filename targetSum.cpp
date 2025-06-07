class Solution {
public:
    vector<int> nums;
    int target;
    int sol;
    int findTargetSumWays(vector<int>& nums, int target) 
    { 
        this->nums = nums;
        this->target = target;
        dp(0, 0);
        return sol;
    }
    void dp(int curr, int idx)
    {
        if(idx == nums.size())
        {
            if(curr == target)
            {
                sol++;
            }
            return;
        }
        dp(curr - nums[idx], idx + 1);
        dp(curr + nums[idx], idx + 1);
    }
};