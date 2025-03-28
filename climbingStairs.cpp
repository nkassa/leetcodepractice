class Solution {
public:
    vector<int> steps;
    int climbStairs(int n) 
    {
        if(n <= 3)
        {
            return n;
        }
        steps = vector(n+1, -1);
        steps[0] = 1;
        steps[1] = 1;
        return dp(n);
    }
    int dp(int idx)
    {
        if(steps[idx] >= 0)
        {
            return steps[idx];
        }
        steps[idx] = dp(idx-2) + dp(idx-1);
        return steps[idx];
    }
};