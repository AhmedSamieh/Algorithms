class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;

        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            carry += *iter;
            *iter = carry % 10;
            carry /= 10;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};