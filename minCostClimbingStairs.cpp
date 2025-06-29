class Solution {
public:
    vector<int> memo;
    vector<int> cost;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        this->cost = cost;
        memo = vector(cost.size(), -1);
        memo[0] = cost[0];
        memo[1] = cost[1];
        return min(dp(cost.size()-1), dp(cost.size()-2));
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = min(dp(idx-1), dp(idx-2)) + cost[idx];
        return memo[idx];
    }
};