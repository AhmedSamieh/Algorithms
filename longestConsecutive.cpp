class Solution
{
public:
    int dfs(unordered_set<int> &s, int num)
    {
        if (s.find(num) == s.end()) {
            return 0;
        }

        s.erase(num);
        return 1 + dfs(s, num - 1) + dfs(s, num + 1);
    }
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 0;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<int> s(nums.begin(), nums.end());

        while (s.size()) {
            longest = max(longest, dfs(s, *s.begin()));
        }

        return longest;
    }
};