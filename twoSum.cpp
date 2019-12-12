class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_multimap<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            m.emplace(nums[i], i);
        }
        for (auto n1 = m.begin(); n1 != m.end(); ++n1)
        {
            int delta = target - n1->first;
            auto range = m.equal_range(delta);
            for (auto n2 = range.first; n2 != range.second; ++n2)
            {
                if (n1->second != n2->second)
                {
                    ret.push_back(n1->second);
                    ret.push_back(n2->second);
                    return ret;
                }
            }
        }
        return ret;
    }
};