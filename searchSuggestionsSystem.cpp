class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        set<string> ds(products.begin(), products.end());
        vector<vector<string>> res(searchWord.size(), vector<string>());
        string str = "";
        for (int i = 0; i < searchWord.size(); ++i) {
            str += searchWord[i];
            auto iter = ds.lower_bound(str);
            int n = 0;
            auto mystrcmp = [](string& s1, string& s2) {
                for (int i = min(s1.size(), s2.size()) - 1; i >= 0; --i) {
                    if (s1[i] != s2[i]) return false;
                }
                return true;
            };
            while (n < 3 && iter != ds.end() && mystrcmp(const_cast<string &>(*iter), str)) {
                res[i].emplace_back(*iter);
                ++iter;
                ++n;
            }
        }
        return res;
    }
};
static const auto fast=[](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();