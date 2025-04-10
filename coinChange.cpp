class Solution {
public:
    vector<int> memo;
    vector<int> coins;
    int curr;
    int coinChange(vector<int>& coins, int amount) 
    {
        this->coins = coins;
        memo = vector(amount+1, amount+12);
        memo[0] = 0;
        curr = amount;
        amount += 1;
        return dp(amount-1, amount);
    }
    int dp(int idx, int amount)
    {
        if(memo[idx] != amount)
        {
            return memo[idx];
        }
        for(int i = 0; i < coins.size(); i++)
        {
            if(curr - coins[i] >= 0)
            {
                curr -= coins[i];
                memo[idx] = min(memo[idx], dp(curr, amount) + 1);
                curr += coins[i];
            }
        }
        return memo[idx];
    }
};