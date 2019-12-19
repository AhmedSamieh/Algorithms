/*
Given a string S, return the number of substrings that have only one distinct letter.
Input: S = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.
*/
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
                    s.insert(S.substr(i, 1 + j - i));
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
            num += (n * (n + 1)) >> 1;
            i = j;
        }
        return num;
    }
};