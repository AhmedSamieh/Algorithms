static const auto fast = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}
();
class Solution
{
    int searchInsertHelper(vector<int> &nums, int target, int start, int end)
    {
        if (start == end) {
            if (target <= nums[start]) {
                return start;
            } else {
                return start + 1;
            }
        }

        int pivot = (start + end) >> 1;

        if (nums[pivot] >= target) {
            return searchInsertHelper(nums, target, start, pivot);
        } else {
            return searchInsertHelper(nums, target, pivot + 1, end);
        }

    }
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return searchInsertHelper(nums, target, 0, nums.size() - 1);
    }
};