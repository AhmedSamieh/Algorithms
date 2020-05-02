class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int x, y;
        multiset<int, greater<int>> s(stones.begin(), stones.end());

        while (s.size() > 1) {
            y = *s.begin();
            s.erase(s.cbegin());
            x = *s.begin();
            s.erase(s.cbegin());

            if (x != y) {
                s.insert(y - x);
            }
        }

        if (s.size() == 1) {
            return *s.begin();
        }

        return 0;
    }
};