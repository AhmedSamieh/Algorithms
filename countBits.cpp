class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1, 0);
        int step = 0, next_step = 1;
        for (int i = 1; i <= num; ++i)
        {
            if (i == next_step)
            {
                v[i] = 1;
                step = next_step;
                next_step <<= 1;
            }
            else
            {
                v[i] = 1 + v[i ^ step];
            }
        }
        return v;
    }
};