class Solution {
public:
    int strStr(string haystack, string needle) {
        int max_start = haystack.size() - needle.size();
        for (int i = 0; i <= max_start; ++i) {
            int j;
            for (j = 0; j < needle.size() && haystack[i + j] == needle[j]; ++j);
            if (needle.size() == j) {
                return i;
            }
        }
        return -1;
    }
};