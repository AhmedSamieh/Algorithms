class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        return (v.size() & 1) ? v[(v.size() >> 1)] : static_cast<double>(v[(v.size() >> 1)] + v[(v.size() >> 1) - 1]) / 2.0;
    }
};
