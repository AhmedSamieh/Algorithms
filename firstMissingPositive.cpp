class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for (auto i : nums)
        {
            if (i > 0)
            {
                s.insert(i);
            }
        }
        for (int i = 1;; ++i)
        {
            if (s.find(i) == s.end())
            {
                return i;
            }
        }
        return -1;
    }
};