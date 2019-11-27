class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> number_pos;
        for (int i = 0 ; i < B.size(); ++i)
        {
            number_pos.insert(make_pair(B[i], i));
        }
        vector<int> ret;
        for (auto i : A)
        {
            ret.push_back(number_pos[i]);
        }
        return ret;
    }
};