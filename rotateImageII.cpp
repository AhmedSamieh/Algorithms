class Solution
{
    void print(vector<vector<int>> &matrix)
    {
        cout << endl;

        for (auto &row : matrix) {
            for (auto &cel : row) {
                cout << cel << " ";
            }

            cout << endl;
        }

        cout << "------" << endl;
    }
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int temp;
        int n = (matrix.size() - 1);

        for (int i = 0; i <= (matrix.size() >> 1); ++i) {
            for (int j = n - i; j > i; --j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = matrix[j][n - i];
                matrix[j][n - i] = temp;

            }
        }
    }
};
