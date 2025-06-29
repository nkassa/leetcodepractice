class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] * nums[i];
            suffix[n-1-i] = suffix[n-i] * nums[n-1-i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                nums[i] = suffix[i+1];
            }
            else if(i == n-1)
            {
                nums[i] = prefix[i-1];
            }
            else
            {
                nums[i] = prefix[i-1] * suffix[i+1];
            }
        }
        return nums;
    }
};