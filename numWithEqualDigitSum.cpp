class Solution
{
public:
    int solution(vector<int> &nums)
    {
        int sum = 0;
        unordered_map<int, multiset<int, greater<int>>> data; // digitSum, multiset of numbers sorted

        for (auto &num : nums) {
            int digitSum = 0;

            for (int i = num; i > 0; i /= 10) {
                digitSum += i % 10;
            }

            data[digitSum].insert(num);
        }

        for (auto &i : data) {
            if (i.second.size() >= 2) {
                sum = max(sum, *i.second.begin() + *next(i.second.begin(), 1));
            }
        }

        return sum;
    }
};
