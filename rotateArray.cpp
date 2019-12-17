/*
[1,2,3,4,5,6,7] and k = 3
[7,6,5,4,3,2,1] -- rev all
[5,6,7,4,3,2,1] -- rev first k
[5,6,7,1,2,3,4] -- rev the rest

*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        if (nums.size() == 2)  {
            if (k & 1) {
                swap(nums[0], nums[1]);
            }
            return;
        }
        k = k % nums.size();
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for (int i = 0, j = k - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for (int i = k, j = nums.size() - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
};