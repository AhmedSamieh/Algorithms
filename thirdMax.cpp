class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int first, second, third;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        first = *max_element(nums.begin(), nums.end());
        second = third = *min_element(nums.begin(), nums.end());

        for (auto const &x : nums) {
            if (x > second && x < first) {
                second = x;
            }
        }

        for (auto const &x : nums) {
            if (x > third && x < second) {
                third = x;
            }
        }

        if (second == third) {
            return first;
        } else {
            return third;
        }
    }
};
