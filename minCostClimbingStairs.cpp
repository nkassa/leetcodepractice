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
        for(int i = 2; i <= cost.size(); i++)
        {
            if(list[i] >= 0)
            {
                return list[i];
            }
            list[i] = min(list[i-2]+ cost[i-2], list[i-1] + cost[i-1]);
        }
        return list[idx];
    }
};