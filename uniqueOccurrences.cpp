class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrences;
        unordered_set<int> unique;
        for (auto i : arr)
        {
            occurrences[i]++;
        }
        for (auto i : occurrences)
        {
            if (unique.find(i.second) != unique.end())
            {
                return false;
            }
            unique.insert(i.second);
        }
        return true;
    }
};