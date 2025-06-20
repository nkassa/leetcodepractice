class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini = INT_MAX;
        int ans = 0;
        for(int price: prices)
        {
            mini = min(price, mini);
            ans = max(ans, price-mini);
        }
        return ans;
    }
};