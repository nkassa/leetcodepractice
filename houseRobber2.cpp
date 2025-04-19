class Solution {
public:
    vector<int> nums;
    vector<int> memo;
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return 0;
        }
        memo = vector(n, -1);
        memo[0] = nums[0];
        memo[1] = max(nums[])
        for(int i = 0; i < n -1; i++)
        {
            memo[2] = 
        }
    }
};