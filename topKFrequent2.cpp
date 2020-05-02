class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> ret;
        unordered_map<string, int> word_freq;
        map<int, set<string>, greater<int>> freq_words; // freq, set of words

        for (auto &word : words) {
            word_freq[word]++;
        }

        for (auto &word : word_freq) {
            freq_words[word.second].emplace(word.first);
        }

        int i = 0;
        ret.reserve(k);

        for (auto &freq : freq_words) {
            for (auto &word : freq.second) {
                ret.emplace_back(word);

                if (++i == k) {
                    return ret;
                }
            }
        }

        return ret;
    }
};