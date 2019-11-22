class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        if (s.size() > 0)
        {
            vector<int> r_vector;
            vector<int> l_vector;
            int r = 0, l = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == 'R')
                {
                    r++;
                }
                else
                {
                    l++;
                }
                r_vector.push_back(r);
                l_vector.push_back(l);
            }
            for (int i = s.size() - 1; i >= 0; --i)
            {
                if (l_vector[i] == r_vector[i])
                {
                    ++count;
                }
            }
        }
        return count;
    }
};