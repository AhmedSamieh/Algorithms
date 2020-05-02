class Solution
{
    bool isPalindrome(string &s, int start, int end)
    {
        for (int i = start, j = end; i <= j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
public:
    string longestPalindrome(string s)
    {
        //bf
        int length = 0;
        int start = 0;

        for (int i = 0; i < s.size() - length; ++i) {
            for (int j = s.size() - 1; j >= (i + length); --j) {
                if (isPalindrome(s, i, j)) {
                    start = i;
                    length = 1 + j - i;
                }
            }
        }

        return s.substr(start, length);
    }
};