class Solution {
public:
    vector<int> steps;
    int climbStairs(int n) 
    {
        steps = vector(n+1, -1);
        steps[0] = 0;
        step[1] = 1;
        step[2] = 2;
        return dp(n);
    }
    int dp(int idx)
    {
        if(steps[idx] >= 0)
        {
            return steps[idx];
        }
    }
};