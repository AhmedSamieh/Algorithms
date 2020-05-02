class Solution
{
public:
    /*int smallestCommonElement(vector<vector<int>>& mat) {
        map<int, int> common;
        for (auto &row : mat)
        {
            for (auto &i : row)
            {
                common[i]++;
            }
        }
        for (auto &iter : common)
        {
            if (iter.second == mat.size())
            {
                return iter.first;
            }
        }
        return -1;
    }*/
    int smallestCommonElement(vector<vector<int>> &mat)
    {
        if (mat.size() > 0 && mat[0].size() > 0) {
            unordered_set<int> row_limit(mat[0].begin(), mat[0].end());
            map<int, int> common;

            for (int i = 1; i < mat.size(); ++i) {
                for (auto &x : mat[i]) {
                    if (row_limit.find(x) != row_limit.end()) {
                        common[x]++;
                    }
                }
            }

            for (auto &iter : common) {
                if (iter.second == mat.size() - 1) {
                    return iter.first;
                }
            }
        }

        return -1;
    }
};