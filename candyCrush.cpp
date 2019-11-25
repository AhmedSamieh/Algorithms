class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (true)
        {
            stack< pair< pair<int, int>, pair<int, int> > > s; // start i, j .. stop i, j
            // find valid ranges to crush
            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board[0].size(); ++j)
                {
                    if (board[i][j] != 0)
                    {
                        if (j - 1 >= 0 &&
                            j + 1 < board[0].size() &&
                            board[i][j] == board[i][j - 1] &&
                            board[i][j] == board[i][j + 1])
                        {
                            s.push(make_pair(make_pair(i, j - 1), make_pair(i, j + 1)));
                        }
                        if (i - 1 >= 0 &&
                            i + 1 < board.size() &&
                            board[i][j] == board[i - 1][j] &&
                            board[i][j] == board[i + 1][j])
                        {
                            s.push(make_pair(make_pair(i - 1, j), make_pair(i + 1, j)));
                        }
                    }
                }
            }
            //cout << s.size() << endl;
            if (s.empty()) // no ranges found
            {
                break;
            }
            // zero ranges
            while (!s.empty())
            {
                //cout << "from [" << s.top().first.first << ", " << s.top().first.second << "] to ["
                //                 << s.top().second.first << ", " << s.top().second.second << "]" << endl;
                for (int i = s.top().first.first; i <= s.top().second.first; i++)
                {
                    for (int j = s.top().first.second; j <= s.top().second.second; j++)
                    {
                        board[i][j] = 0;
                    }
                }
                s.pop();
            }
            for (int j = 0; j < board[0].size(); ++j)
            {
                // move zeros up
                for (int i = board.size() - 1; i > 0; --i)
                {
                    if (board[i][j] == 0)
                    {
                        int k;
                        for (k = i - 1; k >= 0; --k)
                        {
                            if (board[k][j] != 0)
                            {
                                swap(board[i][j], board[k][j]);
                                break;
                            }
                        }
                        if (k < 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
        return board;
    }
};