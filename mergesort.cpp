class Solution
{
    void mergesort(vector<int> &nums, vector<int> &temp, int start, int end)
    {
        if (start >= end) {
            return;
        }

        int pivot = (start + end) >> 1;
        mergesort(nums, temp, start, pivot);
        mergesort(nums, temp, pivot + 1, end);
        merge(nums, temp, start, end);
    }
    void merge(vector<int> &nums, vector<int> &temp, int start, int end)
    {
        int i = start;
        int pivot = (start + end) >> 1;
        int j = pivot + 1;
        int k = 0;

        while (i <= pivot && j <= end) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= pivot) {
            temp[k++] = nums[i++];
        }

        while (j <= end) {
            temp[k++] = nums[j++];
        }

        // copy back to the original vector
        for (i = 0; i < k; ++i) {
            nums[start + i] = temp[i];
        }
    }
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> temp(nums.size());
        //sort(nums.begin(), nums.end());
        mergesort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};