class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        unsigned long x = abs(static_cast<long>(dividend));
        unsigned long y = abs(static_cast<long>(divisor));
        if (x < y) {
            return 0;
        }
        bool sign = (dividend < 0) ^ (divisor < 0);
        unsigned long ret = 0;
        unsigned long long constructed_x = 0;
        for (int i = 30; i >= 0; --i) {
            unsigned long long delta = y << i;
            constructed_x += delta;
            if (constructed_x > x) {
                constructed_x -= delta;
            }
            else {
                ret |= 1 << i;
            }
        }
        return sign ? -ret : (ret < INT_MAX ? ret : INT_MAX);
    }
};
