#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ret;
#if 0
        unordered_set<int> s(nums.begin(), nums.end());

        for (int i = 1; i <= nums.size(); ++i) {
            if (s.find(i) == s.end()) {
                ret.push_back(i);
            }
        }

#else
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;

        while (i < nums.size()) {
            if (j == nums[i]) {
                ++j;
                ++i;
            } else if (j < nums[i]) {
                ret.push_back(j);
                ++j;
            } else { // if (j > nums[i])
                ++i;
            }
        }

        for (int i = j; i <= nums.size(); ++i) {
            ret.push_back(i);
        }

#endif
        return ret;
    }
};

int main(int argc, char **argv)
{
    vector<int> v {9, 2, 4, 3, 6, 2, 8, 3, 10, 3};
    Solution sol;
    auto u = sol.findDisappearedNumbers(v);

    for (auto &i : u) {
        cout << i << endl;
    }

    return 0;
}
