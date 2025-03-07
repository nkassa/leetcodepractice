class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[nums.size()-1];
        int left = 1;
        int right = nums.size()-2;
        while(left < nums.size())
        {
            prefix[left] = prefix[left-1] * nums[left];
            suffix[right] = suffix[right+1] * nums[right]);
            left++;
            right--;
        }
        vector<int> ans(nums.size());
        ans[0] = suffix[nums.size];
        ans[nums.size()-1] = prefix[nums.size() - 2];
        for(int i = 1; i < nums.size()-1; i++)
        {
            cout << prefix[i-1] << " " <<  suffix[i+1] << endl;
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};



// 1   2   6   24
// 24  24  12  4