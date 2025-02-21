class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int left = prices[0];
        int maxi = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            left = min(left, prices[i]);
            if(left < prices[i])
            {
                cout << prices[i]- left << endl;
                maxi = max(maxi, prices[i]-left);
            }
        }
        return maxi;
    }
};