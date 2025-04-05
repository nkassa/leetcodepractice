class Solution {
public:

    long long n;
    long long ans;

    int coinChange(vector<int>& coins, int amount) 
    {
        n = coins.size();
        ans = LONG_MAX;

        int curr = 0;
        backtrack(curr, amount, coins, 0);
        if(ans == LONG_MAX)
        {
            return -1;
        }
        return ans;
    }
    void backtrack(int curr, int amount, vector<int>& coins, long long int size)
    {
        if(amount == 0)
        {
            ans = min(size, ans);
            return;
        }
        else if(amount < 0)
        {
            return;
        }
        for(int i = 0; i < coins.size(); i++)
        {
            curr += coins[i];
            amount -= coins[i];
            size += 1;
            backtrack(curr, amount, coins, size);
            curr -= coins[i];
            amount += coins[i];
            size -= 1;
        }
    }
};