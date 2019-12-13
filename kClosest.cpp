class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        ret.reserve(K);
        multimap<unsigned long int, int> distance_index; // distance, index of point in input
        for (int i = 0; i < points.size(); ++i) {
            distance_index.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int k = 0;
        for (auto &i : distance_index) {
            ret.emplace_back(points[i.second]);
            if (++k == K) {
                break;
            }
        }
        return ret;
    }
};
