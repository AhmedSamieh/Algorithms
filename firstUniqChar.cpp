class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> unique_char_index;
        unordered_set<char> repeated_char;
        for (int i = 0; i < s.size(); ++i) {
            if (repeated_char.find(s[i]) == repeated_char.end()) {
                auto iter = unique_char_index.find(s[i]);
                if (iter == unique_char_index.end()) {
                    unique_char_index.emplace(s[i], i);
                }
                else {
                    unique_char_index.erase(iter);
                    repeated_char.insert(s[i]);
                }
            }
        }
        int index = s.size();
        for (auto &iter : unique_char_index) {
            if (iter.second < index) {
                index = iter.second;
            }
        }
        if (s.size() == index) {
            return -1;
        }
        else {
            return index;
        }
    }
};