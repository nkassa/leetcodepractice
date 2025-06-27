class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size()-1;
        vector<int> prefix(n+1,0);
        vector<int> suffix(n+1,0);
        int sum = 1;
        int backsum = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum *= nums[i];
            backsum *= nums[n-i];
            prefix[i] = sum;
            suffix[n-i] = backsum;
        }
        vector<int> ans(n+1, 0);
        for(int i = 0; i < ans.size(); i++)
        {
            if(i == 0)
            {
                ans[i] = suffix[i+1];
            }
            else if(i == ans.size()-1)
            {
                ans[i] = prefix[i-1];
            }
            else
            {
                ans[i] = prefix[i-1] * suffix[i+1];
            }
        }
        return ans;
    }
};