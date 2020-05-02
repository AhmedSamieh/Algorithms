class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = nums.size() - 1;

        do {
            // find next val
            while (i < nums.size()) {
                if (nums[i] == val) {
                    break;
                }

                ++i;
            }

            while (j >= 0) {
                if (nums[j] != val) {
                    break;
                }

                --j;
            }

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        } while (i < j);

        nums.resize(i);
        return i;
    }
};