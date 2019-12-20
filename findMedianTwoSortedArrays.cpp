/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(N + M) space
        // O(N + M) complexity
        vector<int> v(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        return (v.size() & 1) ? v[(v.size() >> 1)] : static_cast<double>(v[(v.size() >> 1)] + v[(v.size() >> 1) - 1]) / 2.0;
    }
};*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(1) space
        // O(N + M) complexity
        int total_size = nums1.size() + nums2.size();
        int median_index = (total_size + 1) >> 1;
        int i, i1, i2;
        int median_odd, median_even;
        if (1 == total_size) {
            return (0 == nums1.size()) ? nums2[0] : nums1[0];
        }
        for (i = 0, i1 = 0, i2 = 0; i <= median_index; ++i) {
            median_odd = median_even;
            if (i1 < nums1.size() && i2 < nums2.size()) {
                median_even = (nums1[i1] < nums2[i2]) ? nums1[i1++] : nums2[i2++];
            }
            else if (i1 == nums1.size()) {
                median_even = nums2[i2++];
            }
            else {
                median_even = nums1[i1++];
            }
        }
        if (total_size & 1) {
            return median_odd;
        }
        else {
            return static_cast<double>(median_odd + median_even) / 2;
        }
    }
};