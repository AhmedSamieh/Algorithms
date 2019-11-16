class KthLargest {
    multiset<int> s;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        s.insert(nums.begin(), nums.end());
        if (nums.size() > k)
        {
            s.erase(s.begin(), next(s.begin(), nums.size() - k));
        }
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() > size)
        {
            s.erase(s.begin());
        }
        return *s.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */