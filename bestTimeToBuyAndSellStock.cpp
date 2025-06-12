class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        int mini = INT_MAX;
        for(int price: prices)
        {
            if(mini > price)
            {
                mini = price;
            }
            else
            {
                ans = max(ans, price-mini);
            }
        }
        return ans;
    }
};