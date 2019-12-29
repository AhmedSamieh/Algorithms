class Solution {
public:
    int compress(vector<char>& chars) {
        size_t i, j;
        int count = 1;
        for (i = 0, j = 1; j < chars.size(); ++j) {
            if (chars[j] == chars[i]) {
                count++;
            }
            else {
                if (count >= 2) {
                    string length = to_string(count);
                    for (char c : length) {
                        chars[++i] = c;
                    }
                }
                chars[++i] = chars[j];
                count = 1;
            }
        }
        if (count >= 2) {
            string length = to_string(count);
            for (char c : length) {
                chars[++i] = c;
            }
        }
        chars.resize(++i);
        return i;
    }
};