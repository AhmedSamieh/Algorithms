/*class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2){
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        for (int i = 0; i <= text1.size(); i++)
        {
            for (int j = 0; j <= text2.size(); j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};*/
class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2){
        string *t1, *t2;
        // < optimize for speed, > optimize for memory size
        if (text1.size() < text1.size())
        {
            t1 = &text1;
            t2 = &text2;
        }
        else
        {
            t1 = &text2;
            t2 = &text1;
        }
        vector<int> dp(t2->size() + 1, 0);
        for (int i = 0; i < t1->size(); i++)
        {
            int left = 0, me = 0;
            for (int j = 0; j < t2->size(); j++)
            {
                if ((*t1)[i] == (*t2)[j])
                {
                    me = dp[j] + 1;
                }
                else
                {
                    me = max(left, dp[j + 1]);
                }
                dp[j] = left;
                left = me;
            }
            dp[t2->size()] = me;
        }
        return dp[t2->size()];
    }
};
