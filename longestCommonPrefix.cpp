class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if (strs.size() > 0)
        {
            for (int i = 0; i < strs[0].size(); ++i)
            {
                int j;
                for (j = 1; j < strs.size(); ++j)
                {
                    if (strs[0][i] != strs[j][i])
                    {
                        return s;
                    }
                }
                if (j == strs.size())
                {
                    s += strs[0][i];
                }
            }
        }
        return s;
    }
};