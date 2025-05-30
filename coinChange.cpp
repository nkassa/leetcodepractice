class Solution {
public:
    vector<int> memo;
    vector<int> coins;
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        sort(coins.begin(), coins.end()); // Optional, but helps early break
        memo = vector<int>(amount + 1, -1);
        memo[0] = 0;
        int result = dp(amount);
        return result == INT_MAX ? -1 : result;
    }

    int dp(int idx) {
        if (idx < 0) return INT_MAX;
        if (memo[idx] != -1) return memo[idx];

        int minCoins = INT_MAX;
        for (int coin : coins) {
            if (idx - coin >= 0) {
                int res = dp(idx - coin);
                if (res != INT_MAX) {
                    minCoins = min(minCoins, res + 1);
                }
            } else {
                break;
            }
        }

        memo[idx] = minCoins;
        return memo[idx];
    }
};
