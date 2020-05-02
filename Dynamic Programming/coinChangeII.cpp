/*
    0   1   2   3   4   5  6  7
3   1   0   0   1   0   0  1  0
2   1   0   1   1   2   1  3  1
5   1   0   1   1   2   2  3  2
*/
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i]) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }
};