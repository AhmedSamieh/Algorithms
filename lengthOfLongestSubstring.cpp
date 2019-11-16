class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_set<char> m;
        for (int i = 0, j = 0; i < s.size() - max; ++i)
        {
            for (; j < s.size(); ++j)
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
                    m.erase(s.at(i));
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
