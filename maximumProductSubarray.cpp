class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = INT_MIN;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        ans = prefix[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] * nums[i];
            ans = max(ans, prefix[i]);
        }
        return ans;
    }
};