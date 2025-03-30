class Solution {
public:
    vector<int> list;
    vector<int> nums;
    bool canJump(vector<int>& nums) 
    {
        this->nums = nums;
        list = vector(nums.size(), -1);
        list[0] = nums[0];
        int i = dp(nums.size()-1);
        return i == nums.size()-1;
    }
    int dp(int idx)
    {
        if(list[idx] != -1)
        {
            return list[idx];
        }
        list[idx] = max(dp(idx-1), nums[idx] + idx);
        return list[idx];
    }
};