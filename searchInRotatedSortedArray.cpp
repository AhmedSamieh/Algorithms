class Solution {
    int find(vector<int>& nums, int start, int end, int target) {
        if (start == end) return (nums[start] == target) ? start : -1;
        int pevot = start + ((end - start) >> 1);
        if (nums[start] <= nums[pevot]) {
            if (nums[start] <= target && target <= nums[pevot]) {
                return find(nums, start, pevot, target);
            }
            else {
                return find(nums, pevot + 1, end, target);
            }
        }
        else {
            if (nums[pevot] < target && target <= nums[end]) {
                return find(nums, pevot + 1, end, target);
            }
            else {
                return find(nums, start, pevot, target);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        return find(nums, 0, nums.size() - 1, target);
    }
};