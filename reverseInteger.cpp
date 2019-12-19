class Solution {
public:
    int reverse(int x) {
        bool sign = false;
        long int input = x;
        if (input < 0) {
            sign = true;
            input = -input;
        }
        long int ret_val = 0;
        while (input) {
            ret_val = ret_val * 10 + input % 10;
            input /= 10;
        }
        if (ret_val < INT_MIN || ret_val > INT_MAX) {
            return 0;
        }
        return sign ? -ret_val : ret_val;
    }
};