class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if (nums.size() < 2) {
            return;
        }

        int tail = nums.size() - 1;
        int head = 0;

        while (head <= tail) {
            if (nums[tail] == 2) {
                --tail;
            } else if (nums[head] != 2) {
                ++head;
            } else {
                swap(nums[head], nums[tail]);
                ++head;
                --tail;
            }
        }

        head = 0;

        while (head < tail) {
            if (nums[tail] == 1) {
                --tail;
            } else if (nums[head] != 1) {
                ++head;
            } else {
                swap(nums[head], nums[tail]);
                ++head;
                --tail;
            }
        }
    }
};