class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> curr = {};
        int sum = 0;
        vector<vector<int>> ans;
        dp(curr, sum, ans, target, candidates, 0);
        return ans;
    }
    void dp(vector<int> curr, int sum, vector<vector<int>>& ans, int& target, vector<int>& candidates, int idx)
    {
        if(sum == target)
        {
            ans.push_back(curr);
            return;
        }
        if(sum > target)
        {
            return;
        }
        for(int i = idx; i < candidates.size(); i++)
        {
            sum += candidates[i];
            curr.push_back(candidates[i]);
            dp(curr, sum, ans, target, candidates, i);
            sum -= candidates[i];
            curr.pop_back();
        }
    }
};