class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> list(amount+1,amount+1);
        list[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0)
                {
                    list[i] = min(list[i-coins[j]] + 1, list[i]);
                }
            }
        }
        if(list[amount] >= amount+1)
        {
            return -1;
        }
        return list[amount]; 
    }
};