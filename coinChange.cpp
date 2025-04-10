class Solution {
public:
    vector<int> memo;
    vector<int> coins;
    int n = 0;
    int coinChange(vector<int>& coins, int amount) 
    {
        this->coins = coins;
        n = amount + 1;
        memo = vector(amount+1, n);
        memo[0] = 0;
        return dp(amount);
    }
    int dp(int idx)
    {
        if(memo[idx] != amount)
        {
            return memo[idx];
        }
        
    }
};