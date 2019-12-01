class Solution {
public:
    void reverseWords(vector<char>& s) {
        for (int i = 0; i < s.size(); ++i)
        {
            int j;
            for (j = i; j < s.size() && s[j] != ' '; ++j);
            for (int k = i, l = j - 1; k < l; ++k, --l)
            {
                swap(s[k], s[l]);
            }
            i = j;
        }
        for (int k = 0, l = s.size() - 1; k < l; ++k, --l)
        {
            swap(s[k], s[l]);
        }
    }
};
