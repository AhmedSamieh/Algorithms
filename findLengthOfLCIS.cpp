class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() > 0)
        {
            int longest = 0;
            int count = 0;
            for (int i = 1; i < nums.size(); ++i)
            {
                if (nums[i] > nums[i - 1])
                {
                    ++count;
                }
                else
                {
                    longest = max(longest, count);
                    count = 0;
                }
            }
            return 1 + max(longest, count);
        }
        else
        {
            return 0;
        }
    }
};