class Solution {
public:
    vector<int> list;
    vector<int> nums;
    bool canJump(vector<int>& nums) 
    {
        this->nums = nums;
        list = vector(nums.size(), -1);
        list[0] = 2;
        return nums.size()-1 == dp(nums.size());
    }
    int dp(int idx)
    {
        if(list[idx] != -1)
        {
            return list[idx];
        }

        list[idx] = max(list[idx-1], nums[idx] + idx);
        return list[idx];
    }
};