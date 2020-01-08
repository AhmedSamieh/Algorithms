class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c;
        int i, C = 0;
        for (i = 0; i < a.size() && i < b.size(); ++i) {
            C += ((a[i] == '1') + (b[i] == '1'));
            c.push_back(C & 1 ? '1':'0');
            C >>= 1;
        }
        for (; i < a.size(); ++i) {
            C += (a[i] == '1');
            c.push_back(C & 1 ? '1':'0');
            C >>= 1;
        }
        for (; i < b.size(); ++i) {
            C += (b[i] == '1');
            c.push_back(C & 1 ? '1':'0');
            C >>= 1;
        }
        if (C) {
            c.push_back('1');
        }
        reverse(c.begin(), c.end());
        return c;
    }
};