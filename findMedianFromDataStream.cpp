static const auto fast = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}
();
class MedianFinder
{
    multiset<int, greater<int>> small_group;
    multiset<int> large_group;
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (num > *large_group.begin()) { // num > smallest in large group
            large_group.insert(num);

            if ((large_group.size() - small_group.size()) > 1) { // inserted a lot in large group
                small_group.insert(*large_group.begin()); // move the smallest to small group
                large_group.erase(large_group.begin());
            }
        } else {
            small_group.insert(num);

            if ((small_group.size() - large_group.size()) > 1) { // inserted a lot in small group
                large_group.insert(*small_group.begin()); // move the largest to large group
                small_group.erase(small_group.begin());
            }
        }
    }

    double findMedian()
    {
        if (small_group.size() == 0 && large_group.size() == 0) {
            return 0;
        }

        if (small_group.size() == large_group.size()) { // even
            // avg largest in the small and smallest in the large
            return (*small_group.begin() + *large_group.begin()) / 2.0;
        } else if (small_group.size() > large_group.size()) {
            return *small_group.begin();
        } else {
            return *large_group.begin();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */