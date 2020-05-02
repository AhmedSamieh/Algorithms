class Solution
{
public:
    bool isArmstrong(int N)
    {
        int input = N;
        vector<int> digits;
        digits.reserve(10);

        while (input) {
            digits.push_back(input % 10);
            input /= 10;
        }

        int sum = 0;

        for (auto &d : digits) {
            sum += pow(d, digits.size());

            if (sum > N) {
                return false;
            }
        }

        return sum == N;
    }
};
