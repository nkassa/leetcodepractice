class Solution {
public:
    vector<char> opt = {'-', '+'};
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int curr = 0;
        int sol = 0;
        backtracking(curr, sol, nums, target, 0);
        return sol;
    }
    void backtracking(int curr, int& sol, vector<int>& nums, int& target, int size)
    {
        if(size == nums.size() && curr == target)
        {
            sol++;
            return;
        }
        for(int i = size; i < nums.size(); i++)
        {
            for(int j = 0; j < opt.size(); j++)
            {
                if(opt[j] == '-')
                {
                    curr -= nums[i];
                    backtracking(curr, sol, nums, target, size+1);
                    curr += nums[i];
                }
                else
                {
                    curr += nums[i];
                    backtracking(curr, sol, nums, target, size+1);
                    curr -= nums[i];
                }
            }
        }
    }
};