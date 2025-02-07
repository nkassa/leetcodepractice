class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> seen;
        for(int i = 0; i < nums.size()-2; i++)
        {
            int x = nums[i];
            
            int left = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                if(0 == nums[left] + nums[right] + x)
                {
                    seen.insert({nums[left], nums[right], x});
                    left++;
                    right--;
                }
                else if (0 > nums[left] + nums[right] + x)
                {
                    left++;
                }
                else
                {
                    right--;
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