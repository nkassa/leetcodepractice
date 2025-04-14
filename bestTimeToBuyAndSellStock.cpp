class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        int min = INT_MAX;
        for(auto price: prices)
        {
            if(price < min)
            {
                min = price;
            }
            else
            {
                ans = max(ans, price-min);
            }
        }
        return ans;
    }
};