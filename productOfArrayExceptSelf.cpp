class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[];
        int left = 1;
        int right = nums.size()-2;
        while(left < nums.size())
        {
            prefix.push_back(prefix.back() * nums[left]);
            suffix.push_back(suffix.back() * nums[right]);
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