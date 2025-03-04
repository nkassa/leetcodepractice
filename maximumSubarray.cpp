class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return 0;
        }
        int left = 0;
        int sum = 0;
        int ans = INT_MIN;
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            ans = max(ans, sum);
            if(sum < 0)
            {
                sum = 0;
                left++;
            }
        }
        return ans;
    }
};