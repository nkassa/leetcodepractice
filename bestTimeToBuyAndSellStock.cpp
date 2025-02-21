class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini = INT_MAX;
        int maxi = 0;
        for(int num: prices)
        {
            mini = min(mini, num);
            if(mini < num)
            {
                maxi = max(maxi, num-mini);
            }
        }
        return maxi;
    }
};