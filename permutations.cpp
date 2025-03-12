class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> curr = {};
        unordered_set<int> seen;
        backtrack(ans, curr, nums, seen);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, unordered_set<int> seen)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(seen.find(nums[i]) == seen.end())
            {
                curr.push_back(nums[i]);
                seen.insert(nums[i]);
                backtrack(ans, curr, nums, seen);
                curr.pop_back();
                seen.erase(nums[i]);
            }
        }
    }
};