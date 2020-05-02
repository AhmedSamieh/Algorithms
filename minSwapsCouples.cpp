class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        vector<int> r(row.begin(), row.end());
        unordered_map<int, int> id_seat; // id, seat

        for (int i = 0; i < row.size(); ++i) {
            id_seat[row[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < row.size(); i += 2) {
            int my_couple;

            if (r[i] & 1) {
                my_couple = r[i] - 1;
            } else {
                my_couple = r[i] + 1;
            }

            if (r[i + 1] != my_couple) {
                ++swaps;
                int my_couple_old_set = id_seat[my_couple];
                id_seat[r[i + 1]] = my_couple_old_set;
                id_seat.erase(my_couple);
                swap(r[my_couple_old_set], r[i + 1]);
            }
        }

        return swaps;
    }
};