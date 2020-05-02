class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        // bf
        vector<int> ret;

        for (int i = left; i <= right; i++) {
            if ((i % 1000) == 0) {
                i += 110;
                continue;
            } else if ((i % 100) == 0) {
                i += 10;
                continue;
            } else if ((i % 10) == 0) {
                continue;
            } else {
                string number = to_string(i);
                int j;

                for (j = 0; j < number.size(); ++j) {
                    char digit[] = {0, 0};
                    digit[0] = number[j];
                    int d = atoi(digit);

                    if (d == 0 || (i % d) != 0) {
                        break;
                    }
                }

                if (j == number.size()) {
                    ret.push_back(i);
                }
            }
        }

        return ret;
    }
};