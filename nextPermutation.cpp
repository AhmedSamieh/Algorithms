class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int end = nums.size() - 1;

        for (int i = end - 1; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                // BS: get the next large digit
                int head = i + 1;
                int tail = end;

                while (head < tail) {
                    int pivot = (head + tail) >> 1;

                    if (nums[pivot + 1] > nums[i]) {
                        head = pivot + 1;
                    } else {
                        tail = pivot;
                    }
                }

                swap(nums[i], nums[head]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        sort(nums.begin(), nums.end());
    }
};