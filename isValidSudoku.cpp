class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            bool visited_row[9] = {false};
            bool visited_col[9] = {false};
            for (int j = 0; j < board.size(); ++j) {
                if (isdigit(board[i][j])) {
                    if (visited_row[static_cast<int>(board[i][j] - '1')]) {
                        return false;
                    }
                    visited_row[static_cast<int>(board[i][j] - '1')] = true;
                }
                if (isdigit(board[j][i])) {
                    if (visited_col[static_cast<int>(board[j][i] - '1')]) {
                        return false;
                    }
                    visited_col[static_cast<int>(board[j][i] - '1')] = true;
                }
            }
        }
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                bool visited[9] = {false};
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (isdigit(board[k][l])) {
                            if (visited[static_cast<int>(board[k][l] - '1')]) {
                                return false;
                            }
                            visited[static_cast<int>(board[k][l] - '1')] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};