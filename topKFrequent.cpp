class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> num_freq; // num, freq
        multimap<int, int, greater<int>> freq_num; // freq, num
        for (auto i : nums) {
            num_freq[i]++;
        }
        for (auto i : num_freq) {
            freq_num.emplace(i.second, i.first);
        }
        res.reserve(k);
        auto iter = freq_num.begin();
        for (int i = 0; i < k; ++i, ++iter) {
            res.emplace_back(iter->second);
        }
        return res;
    }
};