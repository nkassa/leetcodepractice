class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        set<vector<int>> seen;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            int left = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    seen.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        for(auto key: seen)
        {
            ans.push_back(key);
        }
        return ans;
    }
};