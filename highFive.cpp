class Solution
{
public:
    vector<vector<int>> highFive(vector<vector<int>> &items)
    {
        map<int, multiset<int, greater<int>>> id_scores; // id, set of scores

        for (auto &iter : items) {
            id_scores[iter[0]].insert(iter[1]);
        }

        vector<vector<int>> id_avg(id_scores.size(), vector<int>(2));
        int i = 0;

        for (auto &iter : id_scores) {
            int avg = 0;
            id_avg[i][0] = iter.first;
            auto scr_iter = iter.second.begin();

            for (int j = 0; j < 5; ++j, ++scr_iter) {
                avg += *scr_iter;
            }

            id_avg[i][1] = avg / 5;
            i++;
        }

        return id_avg;
    }
};