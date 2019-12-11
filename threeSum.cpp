class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
#if 0
        multimap<int, int> mm;
        for (int i = 0; i < (nums.size() - 2); ++i)
        {
            for (int j = i + 1; j < (nums.size() - 1); ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k) // O(N^3)
                {
                    if ((nums[i] + nums[j] + nums[k]) == 0)
                    {
                        int large = max(max(nums[i], nums[j]), nums[k]);
                        int small = min(min(nums[i], nums[j]), nums[k]);
                        auto large_begin = mm.lower_bound(large);
                        auto large_end   = mm.upper_bound(large);
                        bool found = false;
                        for (auto z = large_begin; z != large_end; ++z)
                        {
                            if (z->second == small)
                            {
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                        {
                            mm.insert(make_pair(large, small));
                            ret.emplace_back(vector({nums[i], nums[j], nums[k]}));
                        }
                    }
                }
            }
        }
#elif 0
        multimap<int, int> mm;
        unordered_map<int, int> m;
        for (auto &n : nums)
        {
            m[n]++;
        }
        for (auto i = m.begin(); i != m.end(); ++i)
        {
            i->second--;
            for (auto j = i; j != m.end(); ++j) // O(N^2)
            {
                j->second--;
                if (i->second >= 0 && j->second >= 0)
                {
                    auto x = m.find(-(i->first + j->first));
                    if (x != m.end() && x->second > 0)
                    {
                        int large = max(max(i->first, j->first), x->first);
                        int small = min(min(i->first, j->first), x->first);
                        auto large_begin = mm.lower_bound(large);
                        auto large_end   = mm.upper_bound(large);
                        bool found = false;
                        for (auto z = large_begin; z != large_end; ++z)
                        {
                            if (z->second == small)
                            {
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                        {
                            mm.insert(make_pair(large, small));
                            ret.emplace_back(vector({i->first, j->first, x->first}));
                        }
                    }
                }
                j->second++;
            }
            i->second++;
        }
#else
        unordered_map<int, unordered_set<int>> ms;
        unordered_map<int, int> m;
        for (auto &n : nums)
        {
            m[n]++;
        }
        for (auto i = m.begin(); i != m.end(); ++i)
        {
            i->second--;
            for (auto j = i; j != m.end(); ++j) // O(N^2)
            {
                j->second--;
                if (i->second >= 0 && j->second >= 0)
                {
                    auto x = m.find(-(i->first + j->first));
                    if (x != m.end() && x->second > 0)
                    {
                        int large = max(max(i->first, j->first), x->first);
                        int small = min(min(i->first, j->first), x->first);
                        ms[large].insert(small);
                    }
                }
                j->second++;
            }
            i->second++;
        }
        for (auto &large_iter : ms)
        {
            for (auto &small_iter : large_iter.second)
            {
                ret.emplace_back(vector({large_iter.first, small_iter, -(large_iter.first + small_iter)}));
            }
        }
#endif
        return ret;
    }
};