class Solution {
public:
    int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr, candidates, target, 0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& candidates, int target, int start)
    {
        if(start == n)
        {
            if(target == 0)
            {
                ans.push_back(curr);
            }
            return;
        } 
        if(target >= candidates[start])
        {
            curr.push_back(candidates[start]);
            backtrack(ans, curr, candidates, target-candidates[start], start);
            curr.pop_back();
        }
        backtrack(ans, curr, candidates, target, start + 1);
    }
};