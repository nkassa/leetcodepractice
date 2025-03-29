class Solution {
public:
    vector<int> steps;
    int climbStairs(int n) 
    {
        if(n <= 2)
        {
            return n;
        }
        steps = vector(n+1, -1);
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;
        return dp(n);
    }
    int dp(int idx)
    {
        if(steps[idx] >= 0)
        {
            return steps[idx];
        }
        return steps[idx] = steps[idx-2] + steps[idx-1];
    }
};