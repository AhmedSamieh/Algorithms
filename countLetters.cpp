/*class Solution {
public:
    int countLetters(string S) {
        unordered_multiset<string> s;
        for (int i = 0; i < S.size(); ++i)
        {
            s.insert(S.substr(i, 1));
            for (int j = i + 1; j < S.size(); ++j)
            {
                if (S[i] == S[j])
                {
                    s.insert(S.substr(i, (j - i) + 1));
                }
                else
                {
                    break;
                }
            }
        }
        return s.size();
    }
};*/
class Solution {
public:
    int countLetters(string S) {
        int num = 0;
        int i = 0, j = 0;
        while (i < S.size())
        {
            for (j = i; j < S.size() && S[i] == S[j]; ++j);
            int n = j - i;
            num += (n * (n + 1)) / 2;
            i = j;
        }
        return num;
    }
};