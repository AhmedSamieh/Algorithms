/*
n = 4
[0: 0]
[0: 0][1: 1] x
[0: 0][2: 1]
[0: 0][2: 1][1: 2] x
[0: 0][2: 1][3: 2] x
[0: 0][3: 1]
[0: 0][3: 1][1: 2]
[0: 0][3: 1][1: 2][2: 3] x
[0: 0][3: 1][2: 2] x
[1: 0]
[1: 0][0: 1] x
[1: 0][2: 1] x
[1: 0][3: 1]
[1: 0][3: 1][0: 2]
[1: 0][3: 1][0: 2][2: 3] <--
[1: 0][3: 1][2: 2] x
[2: 0]
[3: 0]
*/
class Solution {
    vector<vector<string>> sol;
    bool nothingOnDiagonal(unordered_map<int, int> &occupied, int col)
    {
        for (auto &cel: occupied)
        {
            int row = occupied.size();
            if (abs(row - cel.second) == abs(col - cel.first))
            {
                return false;
            }
        }
        return true;
    }
    void findAllSolutions(unordered_map<int, int> &occupied, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (occupied.find(i) == occupied.end() && nothingOnDiagonal(occupied, i))
            {
                if (occupied.size() == n - 1)
                {
                    // add to sol
                    vector<string> v(n, string(n, '.'));
                    for (auto &cel : occupied)
                    {
                        v[cel.second][cel.first] = 'Q';
                    }
                    v[occupied.size()][i] = 'Q';
                    sol.emplace_back(v);
                    break;
                }
                else
                {
                    unordered_map<int, int> new_solution(occupied);
                    new_solution.emplace(i, occupied.size());
                    findAllSolutions(new_solution, n);
                }
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int, int> initial_solution;
        findAllSolutions(initial_solution, n);
        return sol;
    }
};
