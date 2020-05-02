class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> jewels(J.begin(), J.end());
        int count = 0;

        for (auto &c : S) {
            if (jewels.find(c) != jewels.end()) {
                ++count;
            }
        }

        return count;
    }
};