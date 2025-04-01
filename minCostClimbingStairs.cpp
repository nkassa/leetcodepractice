class Solution {
public:
    vector<int> memo;
    vector<int> cost;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        this->cost = cost;
        memo = vector(cost.size()+1, -1);
        memo[0] = 0;
        memo[1] = 0;

        return dp(cost.size());
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = min(dp(idx-2) + cost[idx-2], dp(idx-1) + cost[idx-1]);
        return memo[idx];
    }
};