class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for (int i = 0; i < s.size() - max; ++i)
        {
            int j;
            unordered_set<char> m;
            m.insert(s.at(i));
            for (j = i + 1; j < s.size(); ++j)
            {
                if (m.count(s.at(j)) == 0)
                {
                    m.insert(s.at(j));
                }
                else
                {
                    if (max < (j - i))
                    {
                        max = j - i;
                    }
                    break;
                }
            }
            if (j == s.size())
            {
                max = j - i;
                break;
            }
        }
        return max;
    }
};
