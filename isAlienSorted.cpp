class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> translate;
        for (int i = 0; i < order.size(); ++i) {
            translate.emplace(order[i], 'a' + i);
        }
        for (auto &word : words) {
            for (auto &c : word) {
                c = translate[c];
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            if (words[i] <= words[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
