class Solution
{
    int sol;
    bool nothingOnDiagonal(unordered_map<int, int> &occupied, int col)
    {
        for (auto &cel : occupied) {
            int row = occupied.size();

            if (abs(row - cel.second) == abs(col - cel.first)) {
                return false;
            }
        }

        return true;
    }
    void findAllSolutions(unordered_map<int, int> &occupied, int n)
    {
        for (int i = 0; i < n; ++i) {
            if (occupied.find(i) == occupied.end() && nothingOnDiagonal(occupied, i)) {
                if (occupied.size() == n - 1) {
                    ++sol;
                    break;
                } else {
                    unordered_map<int, int> new_solution(occupied);
                    new_solution.emplace(i, occupied.size());
                    findAllSolutions(new_solution, n);
                }
            }
        }
    }
public:
    int totalNQueens(int n)
    {
        sol = 0;
        unordered_map<int, int> initial_solution;
        findAllSolutions(initial_solution, n);
        return sol;
    }
};