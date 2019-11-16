class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*multiset<int> s(nums.begin(), nums.end());
        if (nums.size() > k)
        {
            s.erase(s.begin(), next(s.begin(), nums.size() - k));
        }
        return *s.begin();*/
        multiset<int, greater<int>> s(nums.begin(), nums.end());
        return *next(s.begin(), k - 1);
    }
};