/* best for ascending ordered = O(n)
   worest for descending ordered = O(n^2) with a lot of overhead */
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n > 0)
        {
            vector<int> LIS(n, 1);
            multimap<int, int, greater<int>> lis_val;
            lis_val.insert(make_pair(1, nums[0]));
            for (int i = 1; i < n; ++i)
            {
                int rest = n - i;
                auto iter = lis_val.begin();
                while (iter != lis_val.end())
                {
                    if (nums[i] > iter->second)
                    {
                        lis_val.insert(make_pair(iter->first + 1, nums[i]));
                        break;
                    }
                    else if ((iter->first + rest) < lis_val.begin()->first)
                    {
                        break;
                    }
                    ++iter;
                }
                if (iter == lis_val.end() && rest >= lis_val.begin()->first)
                {
                    lis_val.insert(make_pair(1, nums[i]));
                }
            }
            return lis_val.begin()->first;
        }
        else
        {
            return 0;
        }
    }
};*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() > 0)
        {
            vector<int> LIS(nums.size(), 1);
            for (int i = 1; i < nums.size(); ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    // get LIS for every element with all prev elements
                    if (nums[i] > nums[j])
                    {
                        LIS[i] = max(LIS[i], LIS[j] + 1);
                    }
                }
            }
            return *max_element(LIS.begin(), LIS.end());
        }
        else
        {
            return 0;
        }
    }
};