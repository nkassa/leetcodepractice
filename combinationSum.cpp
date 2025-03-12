class Solution {
public:
    int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr, candidates, target, 0, 0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int> candidates, int target, int soFar, int x)
    {
        if(soFar == target)
        {
            ans.push_back(curr);
            return;
        } 
        for(int i = x; i < n; i++)
        {
            if(soFar < target)
            {
                curr.push_back(candidates[i]);
                soFar += candidates[i];
                backtrack(ans, curr, candidates, target, soFar, i);
                curr.pop_back();
                soFar -= candidates[i];
            }
        }
    }
};