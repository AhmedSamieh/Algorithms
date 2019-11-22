class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int count = 0;
        if (grid.size() > 0)
        {
            vector<int> top(grid[0]);
            vector<int> left(1, *max_element(grid[0].begin(), grid[0].end()));
            for (int i = 1; i < grid.size(); ++i)
            {
                left.push_back(*max_element(grid[i].begin(), grid[i].end()));
                for (int j = 0; j < grid[i].size(); ++j)
                {
                    top[j] = max(top[j], grid[i][j]);
                }
            }
            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[i].size(); ++j)
                {
                    count += min(top[j], left[i]) - grid[i][j];
                }
            }
        }
        return count;
    }
};