class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() > 0)
        {
            int n = nums.size();
            vector<int> lis(n, 1);
            vector<int> times(n, 1);
            for (int i = 1; i < n; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (nums[i] > nums[j])
                    {
                        int v = lis[j] + 1;
                        if (lis[i] < v)
                        {
                            lis[i] = v;
                            times[i] = times[j];
                        }
                        else if (lis[i] == v)
                        {
                            times[i] += times[j];
                        }
                    }
                }
            }
            int max_elm = *max_element(lis.begin(), lis.end());
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (lis[i] == max_elm)
                {
                    count += times[i];
                }
            }
            return count;
        }
        else
        {
            return 0;
        }
    }
};