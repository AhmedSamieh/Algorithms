class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int product = 1;

        for (int i = 0; i < nums.size(); ++i) {
            res[i] = product; // product above i
            product *= nums[i];
        }

        product = 1;

        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= product; // product below i * product above i
            product *= nums[i];
        }

        return res;
    }
};
