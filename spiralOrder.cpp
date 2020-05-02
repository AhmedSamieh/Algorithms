class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // (1, 1) .. (1, N)
        // (2, N) .. (M, N)
        // (M, N - 1) .. (M, 1)
        // (M - 1, 1) .. (2, 1)
        // 2, 2 .. 2 , N - 1

        vector<int> ret;
        int m = 0;
        int M = matrix.size() - 1;
        int n = 0;
        int N = matrix.size() > 0 ? (matrix[0].size() - 1) : -1;

        while (m <= M && n <= N) {
            for (int j = n; j <= N; ++j) {
                ret.push_back(matrix[m][j]);
            }

            ++m;

            if (m > M || n > N) {
                break;
            }

            for (int i = m; i <= M; ++i) {
                ret.push_back(matrix[i][N]);
            }

            --N;

            if (m > M || n > N) {
                break;
            }

            for (int j = N; j >= n; --j) {
                ret.push_back(matrix[M][j]);
            }

            --M;

            if (m > M || n > N) {
                break;
            }

            for (int i = M; i >= m; --i) {
                ret.push_back(matrix[i][n]);
            }

            ++n;
        }

        return ret;
    }
};