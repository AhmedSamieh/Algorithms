class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int current = 0;
        for (int next = 1; next < nums.size(); ++next) {
            if (nums[next] > nums[current]) {
                nums[++current] = nums[next];
            }
        }
        nums.resize(current + 1);
        return nums.size();
    }
};