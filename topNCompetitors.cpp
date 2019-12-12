class Solution {
public:
    vector<string> topNCompetitors(vector<string>& competitors, vector<string>& reviews, int N)
    {
        vector<int> freq(competitors.size(), 0);
        for (auto &r : review)
        {
            for (int i = 0; i < competitors.size(); ++i)
            {
                if (r.find(competitors[i]) != string::npos)
                {
                    ++freq[i];
                }
            }
        }
        multimap<int, int, greater<int>> freq_index; // freq, index
        for (int i = 0; i < competitors.size(); ++i)
        {
            freq_index.emplace(freq[i], i);
        }
        vector<string> result;
        result.reserve(N);
        auto iter = freq_index.begin();
        for (int i = 0; i < N; ++i, ++iter)
        {
            result.emplace_back(competitors[iter->second]);
        }
        return result;
    }
};