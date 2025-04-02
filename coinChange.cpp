class Solution {
public:

    int n;
    int ans;

    int coinChange(vector<int>& coins, int amount) 
    {
        n = coins.size();
        ans = n+1;

        int curr = 0;
        backtrack(curr, amount, coins, 0);
        if(ans == n+1)
        {
            return -1;
        }
        return ans;
    }
    void backtrack(int curr, int amount, vector<int>& coins, int size)
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
            backtrack(curr, amount, coins, size+1);
            curr -= coins[i];
            amount += coins[i];
        }
    }
};