/*class Solution {
    unordered_map<long int, double> dp;
    double myPowHelper(double x, long int n) {
        if (n == 0)
        {
            return 1;
        }
        else if (x == 1 || x == 0 || n == 1)
        {
            return x;
        }
        auto iter = dp.find(n);
        if (iter != dp.end())
        {
            return iter->second;
        }
        double ret = myPowHelper(x, n >> 1);
        ret *= ret;
        dp[n] = ret;
        return ret;
    }
public:
    double myPow(double x, int n) {
        double val = 1;
        long int p = abs(static_cast<long int>(n));
        for (int i = 0; (static_cast<long int>(1) << i) <= p ; ++i)
        {
            val *= myPowHelper(x, p & (1 << i));
        }
        return (n > 0)  ? val : (val != 0) ? 1/val : 0;
    }
};*/
class Solution {
public:
    double myPow(double x, int n) {
        vector<double> dp(32, 0);
        double val = 1;
        long int p = abs(static_cast<long int>(n));
        if (n == 0)
        {
            val = 1;
        }
        else if (x == 1 || x == 0 || n == 1)
        {
            val = x;
        }
        else
        {
            dp[0] = x;
            if (p & 1)
            {
                val = x;
            }
            for (int i = 1; (static_cast<long int>(1) << i) <= p ; ++i)
            {
                dp[i] = dp[i - 1] * dp[i - 1];
                if (p & (1 << i))
                {
                    val *= dp[i];
                }
            }
        }
        return (n > 0)  ? val : (val != 0) ? 1/val : 0;
    }
};