class Solution
{
public:
    int myAtoi(string str)
    {
        int num = 0;
        bool first = true;
        bool sign = true;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        for (auto &c : str) {
            if (c >= '0' && c <= '9') {
                first = false;
                long int temp = static_cast<long int>(num) * 10 + static_cast<long int>(c - '0');

                if (temp > INT_MAX) {
                    return sign ? INT_MAX : INT_MIN;
                }

                num = static_cast<long int>(temp);
            } else if (c == '-') {
                if (first) {
                    sign = false;
                    first = false;
                } else {
                    break;
                }
            } else if (c == '+') {
                if (first) {
                    first = false;
                } else {
                    break;
                }
            } else if (c == ' ') {
                if (!first) {
                    break;
                }
            } else {
                break;
            }
        }

        return sign ? num : -num;
    }
};