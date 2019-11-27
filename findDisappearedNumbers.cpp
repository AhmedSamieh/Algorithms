class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> ret;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (s.find(i) == s.end())
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};