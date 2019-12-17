class Solution {
public:
    int findMin(vector<int>& nums) {
        int tail = nums.size() - 1;
        int head = 0;
        int smallest = nums[0];
        while (head < tail && nums[tail] <= nums[head]) {
            smallest = min(smallest, nums[tail--]);
            ++head;
        }
        return min(nums[head], smallest);
    }
};