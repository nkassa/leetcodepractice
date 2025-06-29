class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> curr = {};
        vector<bool> seen(nums.size(), false);
        backtrack(ans, curr, nums, seen);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, vector<bool>& seen)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(seen[i] == false)
            {
                curr.push_back(nums[i]);
                seen[i] = true;
                backtrack(ans, curr, nums, seen);
                curr.pop_back();
                seen[i] = false;
            }
        }
    }
};