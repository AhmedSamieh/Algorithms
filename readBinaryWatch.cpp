class Solution
{
public:
    int bits_count(int val)
    {
        int num = 0;

        for (int i = 0; i < 10; i++) {
            if (val & (1 << i)) {
                num++;
            }
        }

        return num;
    }
    vector<string> readBinaryWatch(int num)
    {
        vector<string> ret;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (bits_count(i << 6 | j) == num) {
                    char buffer[6];
                    sprintf(buffer, "%d:%02d", i, j);
                    ret.emplace_back(buffer);
                }
            }
        }

        return ret;
    }
};