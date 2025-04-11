class Solution {
public:
    vector<int> memo;
    vector<int> coins;
    int n = 0;
    int amount;
    int coinChange(vector<int>& coins, int amount) 
    {
        this->amount= amount;
        this->coins = coins;
        n = amount + 1;
        memo = vector(n, n);
        memo[0] = 0;
        return dp(amount);
    }
    int dp(int idx)
    {
        if(memo[idx] != n)
        {
            return memo[idx];
        }
        for(int i = 0; i < coins.size(); i++)
        {
            if(idx - coins[i] >= 0)
            {
                memo[idx] = min(memo[idx], dp(idx-coins[i]) + 1);
            }
        }
        return memo[idx];
    }
};