class Solution {
public:
    vector<int> list;
    vector<int> nums;
    int rob(vector<int>& nums) 
    {
        this->nums = nums;
        if(nums.size() == 1)
        {
            return nums[0];
        }
        else if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        list = vector(nums.size(), -1);
        list[0] = nums[0];
        list[1] = max(nums[0], nums[1]);
        return dp(nums.size()-1);
    }
    int dp(int idx)
    {
        if(list[idx] != -1)
        {
            return list[idx];
        }
        list[idx] = max(dp(idx-2)+nums[idx], dp(idx-1));
        return list[idx];
    }
};