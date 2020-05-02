class Solution
{
    int find(vector<int> &nums, int start, int end, int target)
    {
        if (start == end) {
            return (nums[start] == target) ? start : -1;
        }

        int pivot = (start + end) >> 1;

        if (nums[start] <= nums[pivot]) {
            if (nums[start] <= target && target <= nums[pivot]) {
                return find(nums, start, pivot, target);
            } else {
                return find(nums, pivot + 1, end, target);
            }
        } else {
            if (nums[pivot] < target && target <= nums[end]) {
                return find(nums, pivot + 1, end, target);
            } else {
                return find(nums, start, peiot, target);
            }
        }
    }
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0) {
            return -1;
        }

        return find(nums, 0, nums.size() - 1, target);
    }
};