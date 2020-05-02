#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

double dist(const pair<int, int> &p1, const pair<int, int> &p2)
{
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return sqrt(static_cast<double>((x * x) + (y * y)));
}
vector<pair<int, int>> getKClosest(vector<pair<int, int>> &points, pair<int, int> &point, int k)
{
    if (k >= points.size()) {
        return points;
    }

    vector<pair<int, int>> ret;

    if (k > 0) {
        multimap<double, size_t, greater<double>> ds;

        for (size_t i = 0; i < points.size(); ++i) {
            ds.emplace(dist(point, points[i]), i);

            if (ds.size() > k) {
                ds.erase(ds.begin());
            }
        }

        ret.reserve(k);

        for (auto &i : ds) {
            ret.emplace_back(points[i.second]);
        }
    }

    return ret;
}
int main(int argc, char **argv)
{
    vector<pair<int, int>> points {make_pair(-5, 7), make_pair(12, 4), make_pair(6, 8), make_pair(4, 5), make_pair(-1, 1)};
    auto point = make_pair(2, 3);
    auto ret = getKClosest(points, point, 3);

    for (auto &i : ret) {
        cout << i.first << ", " << i.second << endl;
    }
}
