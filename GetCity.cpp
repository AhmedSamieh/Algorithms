// not tested
int getCity(vector<int> &from, vector<int> &to, vector<int> &weight, int distanceThreshold)
{
    int city = -1;
    map<int, int> m; // city, # connections

    for (int i = 0; i < from.size(); ++i) {
        m[from[i]]++;
        m[to[i]]++;
    }

    for (int i = 0; i < weight.size(); ++i) {
        if (weight[i] <= distanceThreshold) {
            int new_city;

            if (m[from[i]] < m[to[i]]) {
                new_city = from[i];
            } else if (m[from[i]] == m[to[i]]) {
                new_city = max(from[i], to[i]);
            } else {
                new_city = to[i];
            }

            if (city == -1) {
                city = new_city;
            } else if (m[new_city] < m[city] || (m[new_city] == m[city] && new_city > city)) {
                city = new_city;
            }
        }
    }

    return i;
}