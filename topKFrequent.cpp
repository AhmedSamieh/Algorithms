class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_freq; // num, freq
        for (auto i : nums)
        {
            num_freq[i]++;
        }
        multimap<int, int, greater<int>> freq_num; // freq, num
        for (auto i : num_freq)
        {
            freq_num.emplace(i.second, i.first);
        }
        vector<int> res(k);
        auto iter = freq_num.begin();
        for (int i = 0; i < k; ++i, ++iter)
        {
            res[i] = iter->second;
        }
        return res;
    }
};