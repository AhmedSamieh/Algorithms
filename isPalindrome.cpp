/*class Solution {
public:
    bool isPalindrome(string s) {
        const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                                 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6',
                                 '7', '8', '9'};
        unordered_set<char> good(alphabet, alphabet + size(alphabet));
        string v;
        for (auto &c : s)
        {
            char lc = tolower(c);
            if (good.find(lc) != good.end())
            {
                v.push_back(lc);
            }
        }
        for (int i = 0, j = v.size() - 1; i < j; ++i, --j)
        {
            if (v[i] != v[j])
            {
                return false;
            }
        }
        return true;
    }
};*/
class Solution {
    bool isAlphaNum(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char si = tolower(s[i]);
            if (!isAlphaNum(si)) {
                ++i;
                continue;
            }
            char sj = tolower(s[j]);
            if (!isAlphaNum(sj)) {
                --j;
                continue;
            }
            if (si != sj) {
                return false;
            }
            ++i,
            --j;
        }
        return true;
    }
};