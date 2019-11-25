class Solution {
    int coinChangeHelper(vector<int>& coins, int amount, vector<int>& dp) {
        int minCoins = INT_MAX;
        if (amount < 0)
        {
            return -1;
        }
        if (dp[amount] != INT_MAX)
        {
            return dp[amount];
        }
        for (auto coin : coins)
        {
            int c = coinChangeHelper(coins, amount - coin, dp);
            if (c != -1 && c < minCoins)
            {
                minCoins = c;
            }
        }
        if (minCoins == INT_MAX)
        {
            minCoins = -1;
        }
        else
        {
            ++minCoins;
        }
        dp[amount] = minCoins;
        return minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        dp[0] = 0;
        return coinChangeHelper(coins, amount, dp);
    }
};