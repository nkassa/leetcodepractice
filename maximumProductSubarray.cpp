class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = INT_MIN;
        int left_side = 1;
        int right_side = 1;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            left_side *= nums[i];
            right_side *= nums[n-1-i];
            ans = max({ans, left_side, right_side});
            if(left_side == 0)
            {
                left_side = 1;
            }
            if(right_side == 0)
            {
                right_side = 1;
            }
        }
        return ans;
    }
};