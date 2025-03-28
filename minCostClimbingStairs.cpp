class Solution {
public:
    vector<int> list;
    vector<int> cost;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        this->cost = cost;
        list = vector(cost.size()+1, -1);
        list[0] = 0;
        list[1] = 0;
        return dp(cost.size());
    }
    int dp(int idx)
    {
        if(list[idx] >= 0)
        {
            return list[idx];
        }
        list[idx] = min(dp(idx-2) + cost[idx-2], dp(idx-1) + cost[idx-1]);
        return list[idx];
    }
};