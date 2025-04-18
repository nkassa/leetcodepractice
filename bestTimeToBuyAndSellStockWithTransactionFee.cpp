class Solution {
public:
    vector<int> prices;
    vector<vector<int>> memo;
    int fee;
    int maxProfit(vector<int>& prices, int fee) 
    {
        this->prices = prices;
        this->fee = fee;
        memo = vector(prices.size(), vector<int>(2, -1));
        return dp(0, 0);
    }
    int dp(int i, int holding)
    {
        if(i == prices.size())
        {
            return 0;
        }
        if(memo[i][holding] != -1)
        {
            return memo[i][holding];
        }
        int ans = dp(i+1, holding);
        if(holding == 1)
        {
            ans = max(ans, prices[i] + dp(i+1, 0) - fee);
        }
        else
        {
            ans = max(ans, dp(i+1, 1) - prices[i]);
        }
        memo[i][holding] = ans;
        return memo[i][holding];
    }
};