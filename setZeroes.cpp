class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> row;
        unordered_set<int> col;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto &i : row) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] = 0;
            }
        }

        for (auto &j : col) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][j] = 0;
            }
        }
    }
};