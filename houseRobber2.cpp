class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();
        vector<int> memo;
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> numsTwo;
        for(int i = 1; i < nums.size(); i++)
        {
            numsTwo.push_back(nums[i]);
        }

        memo = vector(nums.size(), 0);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size()-1; i++)
        {
            memo[i] = max(memo[i-2]+ nums[i], memo[i-1]);
        }
        ans = memo[nums.size()-2];

        memo = vector(numsTwo.size(), 0);
        memo[0] = numsTwo[0];
        memo[1] = max(numsTwo[0], numsTwo[1]);

        for(int i = 2; i < numsTwo.size(); i++)
        {
            memo[i] = max(memo[i-2]+ numsTwo[i], memo[i-1]);
        }
        ans = max(ans, memo[numsTwo.size()-1]);
        return ans;
    }
};