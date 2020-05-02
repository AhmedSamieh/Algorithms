class Solution
{
public:
    bool isLongerString(string &s1, string &s2)
    {
        return (s1.size() > s2.size());
    }
    string longestWordSubsequence(string &s, vector<string> &d)
    {
        /* naive */
        sort(d.begin(), d.end(), isLongerString);

        for (auto const & w in d) {
            for (int i = 0, j = 0; i < w.size() && j < s.size(); j++) {
                if (w[i] == s[j]) {
                    i++;
                }
            }
        }
    }
};
