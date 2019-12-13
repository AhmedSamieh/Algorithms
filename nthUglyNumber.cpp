class Solution {
public:
    /*int nthUglyNumber(int n) {
        set<unsigned long> s;
        s.insert(2);
        s.insert(3);
        s.insert(5);
        while (s.size() <= n) {
            for (auto &i : s) {
                s.insert(i * 2);
                s.insert(i * 3);
                s.insert(i * 5);
                if (s.size() >= n << 1) {
                    break;
                }
            }
        }
        int i = 0;
        s.insert(1);
        for (auto &x : s) {
            if (++i == n) {
                return x;
            }
        }
        return 1;
    }*/
    int nthUglyNumber(int n) {
        vector<int> ans(n);
        ans[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            int ugly2 = ans[i2] * 2;
            int ugly3 = ans[i3] * 3;
            int ugly5 = ans[i5] * 5;
            ans[i] = min(ugly2, min(ugly3, ugly5));
            if (ans[i] == ugly2) {
                ++i2;
            }
            if (ans[i] == ugly3) {
                ++i3;
            }
            if (ans[i] == ugly5) {
                ++i5;
            }
        }
        return ans[n - 1];
    }
};