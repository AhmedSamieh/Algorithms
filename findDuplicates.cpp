class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_set<int> s;
        vector<int> ret;

        for (int i : nums) {
            if (s.find(i) == s.end()) {
                s.insert(i);
            } else {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
