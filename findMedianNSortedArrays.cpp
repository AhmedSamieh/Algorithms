class Solution {
public:
    double findMedianSortedArrays(vector<vector<int>>& nums) {
        // O(1) space
        // O(min(N, M)) complexity
        int total_size = 0
        for (int i = 0; i < nums.size(); ++i) {
            total_size += nums[i].size();
        }
        int median_index = (total_size + 1) >> 1;
        vector<int> head(nums.size(), 0);
        int median_odd, median_even;
        for (int i = 0; i <= median_index; ++i) {
            median_odd = median_even;
            median_even = INT_MAX;
            int smallest_index = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (head[j] < nums[j].size()) {
                    if (nums[j][head[j]] < median_even) {
                        median_even = nums[j][head[j]];
                        smallest_index = j;
                    }
                }
            }
            head[smallest_index]++;
        }
        if (total_size & 1) {
            return median_odd;
        }
        else {
            return static_cast<double>(median_odd + median_even) / 2;
        }
    }
};