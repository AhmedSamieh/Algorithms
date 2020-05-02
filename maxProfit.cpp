class Solution
{
public:
    /*int maxProfit(vector<int>& prices) { // O(n*n)
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] > prices[i])
                {
                    profit = max(prices[j] - prices[i], profit);
                }
            }
        }
        return profit;
    }*/
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        if (prices.size() > 1) {
            vector<int> buy(prices.size(), prices[0]);
            vector<int> sell(prices.size(), prices[prices.size() - 1]);

            for (int i = 1; i < prices.size(); ++i) {
                buy[i] = min(buy[i - 1], prices[i]);
            }

            for (int i = prices.size() - 2; i >= 0; --i) {
                sell[i] = max(sell[i + 1], prices[i]);
            }

            for (int i = 0; i < prices.size(); ++i) {
                profit = max(profit, sell[i] - buy[i]);
            }
        }

        return profit;
    }
};
