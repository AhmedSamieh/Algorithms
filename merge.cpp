/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                nums1[i] = nums2[i];
            }
        }
        else if (n > 0)
        {
            for (int i = (m + n) - 1, j = m - 1, k = n - 1; i > j; --i)
            {
                if (j >= 0 && nums1[j] > nums2[k])
                {
                    nums1[i] = nums1[j--];
                }
                else
                {
                    nums1[i] = nums2[k--];
                }
            }
        }
    }
};*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = (m + n) - 1, j = m - 1, k = n - 1;

        while (j >= 0 && k >= 0) {
            nums1[i--] = (nums1[j] > nums2[k]) ? nums1[j--] : nums2[k--];
        }

        while (k >= 0) {
            nums1[k] = nums2[k];
            --k;
        }
    }
};