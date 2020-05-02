class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zero = nums.size() + 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (zero > i) {
                    zero = i;
                }
            } else {
                if (zero < i) {
                    nums[zero++] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};