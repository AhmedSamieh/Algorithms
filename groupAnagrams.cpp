class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group_items;
        for (auto &s : strs)
        {
            string temp(s);
            sort(temp.begin(), temp.end());
            group_items[temp].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto &iter : group_items)
        {
            ret.push_back(iter.second);
        }
        return ret;
    }
};
