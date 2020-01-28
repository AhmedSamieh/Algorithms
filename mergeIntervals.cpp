class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), [](vector<int>& i, vector<int>& j) {return i[0] < j[0];});
        int i = 0, j = 1;
        while (j < intervals.size()) {
            if (intervals[j][0] <= intervals[i][1]) {
                if (intervals[j][1] > intervals[i][1]) {
                    intervals[i][1] = intervals[j][1];
                }
            }
            else {
                ret.emplace_back(intervals[i]);
                i = j;
            }
            ++j;
        }
        ret.emplace_back(intervals[i]);
        return ret;
    }
};
